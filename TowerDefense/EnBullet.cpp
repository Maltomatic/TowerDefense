#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "Turret.hpp"
#include "EnBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

class Enemy;

EnBullet::EnBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent) :
	EBullet("play/bullet-12.png", 500, 1, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
	// TODO 2 (1/8): You can imitate the 2 files: 'FireBullet.hpp', 'FireBullet.cpp' to create a new bullet.
}
void EnBullet::OnExplode(Turret* turret) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
	getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), turret->Position.x, turret->Position.y));
}
