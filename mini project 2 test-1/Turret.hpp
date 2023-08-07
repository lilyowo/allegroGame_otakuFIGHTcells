#ifndef TURRET_HPP
#define TURRET_HPP
#include <allegro5/base.h>
#include <list>
#include <string>

#include "Sprite.hpp"

class Enemy;
class EnemyBullet;//minitodo1
class PlayScene;

class Turret: public Engine::Sprite {
protected:
    int price;
    float coolDown;
    float reload = 0;
    float rotateRadian = 2 * ALLEGRO_PI;
    int hp;
    std::list<Turret*>::iterator lockedTurretIterator;
    PlayScene* getPlayScene();
    // Reference: Design Patterns - Factory Method.
    virtual void CreateBullet() = 0;
    //minitodo1
    virtual void OnExplode();
    Engine::Point target;

public:
    bool Enabled = true;
    bool Preview = false;
    Enemy* Target = nullptr;
    Turret(/*std::string imgBase,*/std::string imgTurret, float x, float y,/* float radius,*/ int price, float coolDown, int hp);//minitodo1
    void Hit(float damage);
    void Update(float deltaTime) override;
    void Draw() const override;
	int GetPrice() const;
	//minitodo1
	std::list<Enemy*> lockedEnemys;
	std::list<EnemyBullet*> lockedEnemyBullets;
};
#endif // TURRET_HPP
