#ifndef GARBAGETURRET_HPP
#define GARBAGETURRET_HPP
#include "Turret.hpp"

class GarbageTurret: public Turret {
public:
	static const int Price;
    GarbageTurret(float x, float y);
    void CreateBullet() override;
};
#endif // GARBAGETURRET_HPP
