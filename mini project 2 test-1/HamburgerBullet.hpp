#ifndef HAMBURGERBULLET_HPP
#define HAMBURGERBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class HamburgerBullet : public Bullet {
public:
	explicit HamburgerBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void OnExplode(Enemy* enemy) override;
};
#endif // HAMBURGERBULLET_HPP
