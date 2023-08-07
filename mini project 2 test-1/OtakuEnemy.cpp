#include <allegro5/base.h>
#include <cmath>
#include <string>//

#include "AudioHelper.hpp"
#include "TaneBullet.hpp"
#include "Group.hpp"
#include "OtakuEnemy.hpp"//
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Turret.hpp"



OtakuEnemy::OtakuEnemy(int x, int y) : Enemy("play/enemy-hamster.png", x, y, 20, 50, 150, 80, 4,1) {
	// Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
	// and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}
void OtakuEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(-1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EnemyBulletGroup->AddNewObject(new TaneBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
