#ifndef SOFAENEMYBULLET_HPP
#define SOFAENEMYBULLET_HPP
#include "EnemyBullet.hpp"

class Turret;
class Enemy;
namespace Engine {
struct Point;
}  // namespace Engine

class SofaEnemyBullet : public EnemyBullet {
public:
	explicit SofaEnemyBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* enemy) override;
};
#endif // SOFAENEMYBULLET_HPP
