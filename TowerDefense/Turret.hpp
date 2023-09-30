#ifndef TURRET_HPP
#define TURRET_HPP
#include <allegro5/base.h>
#include <list>
#include <string>

#include "Sprite.hpp"
#include "EBullet.hpp"

class Enemy;
class PlayScene;

class Turret: public Engine::Sprite {
protected:
    int price;
    float coolDown;
    float reload = 0;
    float rotateRadian = 2 * ALLEGRO_PI;
    std::list<Turret*>::iterator lockedTurretIterator;
    PlayScene* getPlayScene();
    virtual void OnExplode();
    // Reference: Design Patterns - Factory Method.
    virtual void CreateBullet() = 0;

public:
    float hp;
    bool Enabled = true;
    bool Preview = false;
    Enemy* Target = nullptr;
    Turret(std::string imgTurret, float x, float y, int price, float coolDown, float hp, int radius);
    void Update(float deltaTime) override;
    virtual void Draw() const override;
	int GetPrice() const;
	std::list<Enemy*> lockedEnemies;
	std::list<EBullet*> lockedEbullets;
	virtual void Hit(float damage);
	void dozed();
};
#endif // TURRET_HPP
