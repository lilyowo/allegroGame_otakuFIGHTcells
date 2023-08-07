#ifndef TANEBULLET_HPP
#define TANEBULLET_HPP
#include "EnemyBullet.hpp"

class Turret;
class Enemy;
namespace Engine {
struct Point;
}  // namespace Engine

class TaneBullet : public EnemyBullet {
public:
	explicit TaneBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* enemy) override;
};
#endif // TANEBULLET_HPP
