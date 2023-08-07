#ifndef GOASTBULLET_HPP
#define GOASTBULLET_HPP
#include "EnemyBullet.hpp"

class Turret;
class Enemy;
namespace Engine {
struct Point;
}  // namespace Engine

class GoastBullet : public EnemyBullet {
public:
	explicit GoastBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* enemy) override;
};
#endif // GOASTBULLET_HPP
