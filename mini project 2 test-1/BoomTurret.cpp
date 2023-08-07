#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "Group.hpp"
#include "BoomTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

const int BoomTurret::Price = 0;
BoomTurret::BoomTurret(float x, float y) :
    // TODO 2 (2/8): You can imitate the 2 files: 'FreezeTurret.hpp', 'FreezeTurret.cpp' to create a new turret.
	Turret("play/bomb.png", x, y, Price, 0.5, 0) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void BoomTurret::CreateBullet() {
}
