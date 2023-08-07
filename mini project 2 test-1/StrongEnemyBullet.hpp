#ifndef STRONGENEMYBULLET_HPP
#define STRONGENEMYBULLET_HPP
#include "EnemyBullet.hpp"

class Turret;
class Enemy;
namespace Engine {
struct Point;
}  // namespace Engine

class StrongEnemyBullet : public EnemyBullet {
public:
	explicit StrongEnemyBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* enemy) override;
};
#endif // STRONGENEMYBULLET_HPP
