#ifndef BOOMTURRET_HPP
#define BOOMTURRET_HPP
#include "Turret.hpp"

class BoomTurret: public Turret {
public:
	static const int Price;
    BoomTurret(float x, float y);
	void CreateBullet() override;
};
#endif // BOOMTURRET_HPP
