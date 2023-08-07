#ifndef ENEMYBULLET_HPP
#define ENEMYBULLET_HPP
#include <string>

#include "Sprite.hpp"

class Turret;
class PlayScene;
class Enemy;
namespace Engine {
struct Point;
}  // namespace Engine

class EnemyBullet : public Engine::Sprite {
protected:
	float speed;
	float damage;
	Enemy* parent;
	PlayScene* getPlayScene();
	virtual void OnExplode(Turret* enemy);
public:
	Turret* Target = nullptr;
	explicit EnemyBullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void Update(float deltaTime) override;
};
#endif // ENEMYBULLET_HPP
