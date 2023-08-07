#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "IceCreamBullet.hpp"
#include "Group.hpp"
#include "GarbageTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"

const int GarbageTurret::Price = 20;
GarbageTurret::GarbageTurret(float x, float y) :
	Turret("play/turret-3.png", x, y, Price, 0.5, 50) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void GarbageTurret::CreateBullet() {
	Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
}

