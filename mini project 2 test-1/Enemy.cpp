#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>
#include <stdio.h>

#include "AudioHelper.hpp"
#include "Bullet.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "ExplosionEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "LOG.hpp"
#include "PlayScene.hpp"
#include "Turret.hpp"

//minitodo1
#include <utility>
#include "IObject.hpp"
#include "Point.hpp"


PlayScene* Enemy::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
void Enemy::OnExplode() {
	getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect(Position.x, Position.y));
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distId(1, 3);
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 20);
	for (int i = 0; i < 10; i++) {
		// Random add 10 dirty effects.
		getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-" + std::to_string(distId(rng)) + ".png", dist(rng), Position.x, Position.y));
	}
}
Enemy::Enemy(std::string img, float x, float y, float radius, float speed, float hp, int money,int type,float coolDown) :
	Engine::Sprite(img, x, y), speed(speed), hp(hp), money(money), type(type), coolDown(coolDown) {
	CollisionRadius = radius;
	reachEndTime = 0;
	Velocity = Engine::Point(speed , 0);
	//OAO
	if(type==4)Velocity = Engine::Point(speed , 60);
	target = Engine::Point(PlayScene::EndGridPointx , static_cast<int>(floor(Position.y / PlayScene::BlockSize))) * PlayScene::BlockSize + Engine::Point(PlayScene::BlockSize / 2, PlayScene::BlockSize / 2);

}
void Enemy::Hit(float damage) {
	hp -= damage;
	//owo
	if(damage==10){
        money+=damage;
        speed=0;
        Velocity.x=0;
        Velocity.y=0;
	}
	if (hp <= 0) {
		OnExplode();
		// Remove all turret's reference to target.
		for (auto& it: lockedTurrets)
			it->Target = nullptr;
		for (auto& it: lockedBullets)
			it->Target = nullptr;
		getPlayScene()->EarnMoney(money);
		getPlayScene()->EnemyGroup->RemoveObject(objectIterator);
		AudioHelper::PlayAudio("explosion.wav");
	}
}
void Enemy::Update(float deltaTime) {
	float remainSpeed = speed * deltaTime;
	PlayScene* scene = getPlayScene();//minitodo1
	if(!Target){//minitodo1
        Position.x -= Velocity.x * deltaTime;
        Position.y += Velocity.y * deltaTime;
	}

	if(Position.x <= PlayScene::EndGridPointx * PlayScene::BlockSize + PlayScene::BlockSize / 2){
		Hit(hp);
		getPlayScene()->Hit();
		reachEndTime = 0;
		return;
	}
	//OAO
	if(Position.y <= 0 || Position.y >= 128*6){
        Velocity.y*=-1;
	}
	if(type==5 && Position.x <= (PlayScene::EndGridPointx + 1000)) Velocity.x *= 1.25;
	Engine::Point vec = target - Position;
	reachEndTime = (vec.Magnitude() - remainSpeed) / speed;
	//minitodo1

	if (Target) {
		if (Target->Position.x < Position.x &&(Position.x - Target->Position.x < 150) && Target->Position.y >= Position.y  && Target->Position.y < Position.y+scene->BlockSize) {
			Target->lockedEnemys.erase(lockedEnemyIterator);
			Target = nullptr;
			lockedEnemyIterator = std::list<Enemy*>::iterator();
		}
		// Shoot reload.
		reload -= deltaTime;
		if (reload <= 0) {
			// shoot.
			reload = coolDown;
			CreateBullet();
		}
	}
	if (!Target) {
		// Lock first seen target.
		// Can be improved by Spatial Hash, Quad Tree, ...
		// However simply loop through all enemies is enough for this program.
		for (auto& it : scene->TowerGroup->GetObjects()) {
                //minitodo1
            if (it->Position.x < Position.x &&(Position.x - it->Position.x < 150) && it->Position.y >= Position.y  && it->Position.y < Position.y+scene->BlockSize) {
				Target = dynamic_cast<Turret*>(it);
				Target->lockedEnemys.push_back(this);
				lockedEnemyIterator = std::prev(Target->lockedEnemys.end());
				break;
			}
		}
	}
}
void Enemy::Draw() const {
	Sprite::Draw();
	if (PlayScene::DebugMode) {
		// Draw collision radius.
		al_draw_circle(Position.x, Position.y, CollisionRadius, al_map_rgb(255, 0, 0), 2);//find3
	}
}
