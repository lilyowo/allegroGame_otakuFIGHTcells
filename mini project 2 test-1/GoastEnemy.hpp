#ifndef GOASTENEMY_HPP
#define GOASTENEMY_HPP
#include "Enemy.hpp"

class GoastEnemy : public Enemy {
public:
	GoastEnemy(int x, int y);
	void CreateBullet() override;
};
#endif // GOASTENEMY_HPP
