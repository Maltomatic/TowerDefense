#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <list>
#include <vector>
#include <string>

#include "Point.hpp"
#include "Sprite.hpp"

class Bullet;
class PlayScene;
class Turret;

class Enemy : public Engine::Sprite {
protected:
	Engine::Point target;
	int money;
	float reload = 0;
	PlayScene* getPlayScene();
	virtual void OnExplode();
    virtual void CreateBullet();
    std::list<Enemy*>::iterator lockedEnemyIterator;

public:
    float cooldown;
    float speed;
    float hp;
	float reachEndTime;
	Turret* Target = nullptr;
	std::list<Turret*> lockedTurrets;
	std::list<Bullet*> lockedBullets;
	Enemy(std::string img, float x, float y, float radius, float speed, float cooldown, float hp, int money );
 	virtual void Hit(float damage);
	void Update(float deltaTime) override;
	void Shoot(float deltaTime);
	void Draw() const override;
};
#endif // ENEMY_HPP
