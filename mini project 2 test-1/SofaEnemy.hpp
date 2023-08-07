#ifndef SOFAENEMY_HPP
#define SOFAENEMY_HPP
#include "Enemy.hpp"

class SofaEnemy : public Enemy {
public:
	SofaEnemy(int x, int y);
	void CreateBullet() override;
};
#endif // SOFAENEMY_HPP
