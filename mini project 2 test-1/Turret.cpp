#include <allegro5/color.h>
#include <allegro5/allegro_primitives.h>
#include <cmath>
#include <utility>

#include "Enemy.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Turret.hpp"
//minitodo1
#include "AudioHelper.hpp"
#include "ExplosionEffect.hpp"
#include <random>
#include <string>
#include <vector>
#include <stdio.h>
#include "DirtyEffect.hpp"
#include "EnemyBullet.hpp"
//minitodo3
#include "Collider.hpp"

PlayScene* Turret::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
Turret::Turret(std::string imgTurret, float x, float y,/* float radius,*/ int price, float coolDown, int hp) ://minitodo1
	Sprite(imgTurret, x, y), price(price), coolDown(coolDown),hp(hp) {
	//CollisionRadius = radius;
	//minitodo1
	target = Engine::Point(PlayScene::EndGridPointx , static_cast<int>(floor(Position.y / PlayScene::BlockSize))) * PlayScene::BlockSize + Engine::Point(PlayScene::BlockSize / 2, PlayScene::BlockSize / 2);
}
void Turret::Update(float deltaTime) {
	Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	if (!Enabled)
		return;
	if (Target) {
		if (Target->Position.x < Position.x&& Target->Position.y >= Position.y  && Target->Position.y < Position.y+scene->BlockSize) {
			Target->lockedTurrets.erase(lockedTurretIterator);
			Target = nullptr;
			lockedTurretIterator = std::list<Turret*>::iterator();
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
		for (auto& it : scene->EnemyGroup->GetObjects()) {
            if (it->Position.x > Position.x && it->Position.y >= Position.y  && it->Position.y < Position.y+scene->BlockSize) {
				Target = dynamic_cast<Enemy*>(it);
				Target->lockedTurrets.push_back(this);
				lockedTurretIterator = std::prev(Target->lockedTurrets.end());
				break;
			}
		}
	}

}
void Turret::Draw() const {
	/*if (Preview) {
		al_draw_filled_circle(Position.x, Position.y, CollisionRadius, al_map_rgba(0, 255, 0, 50));
	}*/
	Sprite::Draw();
	/*if (PlayScene::DebugMode) {
		// Draw target radius.
		al_draw_circle(Position.x, Position.y, CollisionRadius, al_map_rgb(0, 0, 255), 2);
	}*/
	if(price==500)
        al_draw_circle(Position.x, Position.y, 300, al_map_rgb(255, 0, 0), 2);//minitodo3
}
int Turret::GetPrice() const {
	return price;
}

void Turret::Hit(float damage) {
	hp -= damage;
	if (hp <= 0) {
		//OnExplode();
		for (auto& it: lockedEnemys)//find4
			it->Target = nullptr;
		for (auto& it: lockedEnemyBullets)
			it->Target = nullptr;
		getPlayScene()->TowerGroup->RemoveObject(objectIterator);
		AudioHelper::PlayAudio("explosion.wav");
		//minitodo3
		if(price == 500){//acidophil
            for (auto& it : getPlayScene()->EnemyGroup->GetObjects()) {//from plane
                Enemy* enemy = dynamic_cast<Enemy*>(it);
                if (Engine::Collider::IsCircleOverlap(Position, 300, enemy->Position, enemy->CollisionRadius))
                    enemy->Hit(INFINITY);
            }
		}
		//bonus_1
		if(price == 1000){//macrophage
            for (auto& it : getPlayScene()->EnemyGroup->GetObjects()) {//from plane
                Enemy* enemy = dynamic_cast<Enemy*>(it);
                if (enemy->Position.y==Position.y)
                    enemy->Hit(INFINITY);
            }
		}
	}
}
void Turret::OnExplode() {
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
