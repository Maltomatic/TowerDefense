#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "Turret.hpp"
#include "EnBomb.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "EBullet.hpp"
#include "Collider.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "Sprite.hpp"
#include "ExplosionEffect.hpp"

class Enemy;

EnBomb::EnBomb(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent) :
	EBullet("play/bomb.png", 300, 0.3, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
	// TODO 2 (1/8): You can imitate the 2 files: 'FireBullet.hpp', 'FireBullet.cpp' to create a new bullet.
}
void EnBomb::OnExplode(Turret* turret) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
	getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), turret->Position.x, turret->Position.y));

	PlayScene* scene = getPlayScene();
	for(auto it: scene->TowerGroup->GetObjects()){
        Turret* enemy = dynamic_cast<Turret*>(it);
		if (!enemy->Visible)
			continue;
		if (Engine::Collider::IsCircleOverlap(Position, 150, enemy->Position, enemy->CollisionRadius)) {
			enemy->Hit(damage);
			getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect(enemy->Position.x, enemy->Position.y));
		}
	}
}
