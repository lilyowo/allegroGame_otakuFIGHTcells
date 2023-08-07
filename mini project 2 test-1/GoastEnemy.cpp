#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "GoastBullet.hpp"
#include "Group.hpp"
#include "GoastEnemy.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Turret.hpp"

GoastEnemy::GoastEnemy(int x, int y) : Enemy("play/enemy-5.png", x, y, 10, 50, 80, 30, 5,10) {
}
void GoastEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(-1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EnemyBulletGroup->AddNewObject(new GoastBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
