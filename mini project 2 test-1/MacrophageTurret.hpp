#ifndef MACROPHAGETURRET_HPP
#define MACROPHAGETURRET_HPP
#include "Turret.hpp"

class MacrophageTurret: public Turret {
public:
	static const int Price;
    MacrophageTurret(float x, float y);
	void CreateBullet() override;
	void Update(float deltaTime) override;
};
#endif // MACROPHAGETURRET_HPP
