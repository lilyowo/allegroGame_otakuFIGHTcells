#ifndef OTAKUENEMY_HPP
#define OTAKUENEMY_HPP
#include "Enemy.hpp"

class OtakuEnemy : public Enemy {
public:
	OtakuEnemy(int x, int y);
	void CreateBullet() override;
};
#endif // OTAKUENEMY_HPP
