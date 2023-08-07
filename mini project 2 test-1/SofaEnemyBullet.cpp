#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "Turret.hpp"
#include "SofaEnemyBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"

class Enemy;

SofaEnemyBullet::SofaEnemyBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent) :
	EnemyBullet("play/bullet-11.png", 500, 3, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
}
void SofaEnemyBullet::OnExplode(Turret* enemy) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
	getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), enemy->Position.x, enemy->Position.y));
}

