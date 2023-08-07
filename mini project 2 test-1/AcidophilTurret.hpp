#ifndef ACIDOPHILTURRET_HPP
#define ACIDOPHILTURRET_HPP
#include "Turret.hpp"

class AcidophilTurret: public Turret {
public:
	static const int Price;
    AcidophilTurret(float x, float y);
    void CreateBullet() override;
};
#endif // ACIDOPHILTURRET_HPP
