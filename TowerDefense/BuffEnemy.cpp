#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>

#include "BuffEnemy.hpp"
#include "IScene.hpp"
#include "ExplosionEffect.hpp"
#include "HealEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Turret.hpp"
#include "AudioHelper.hpp"
#include "Bullet.hpp"
#include "Collider.hpp"

BuffEnemy::BuffEnemy(int x, int y) : Enemy("play/enemy-5.png", x, y, 25, 60, 1, 7, 20) {
    // TODO 2 (6/8): You can imitate the 2 files: 'NormalEnemy.hpp', 'NormalEnemy.cpp' to create a new enemy.
}

void BuffEnemy::Hit(float damage){
    hp -= damage;
    PlayScene* scene = getPlayScene();
	if (hp <= 0) {
        AudioHelper::PlayAudio("healing.wav");
        for (auto& it : scene->EnemyGroup->GetObjects()) {
            Enemy* enemy = dynamic_cast<Enemy*>(it);
            if (!enemy->Visible)
                continue;
            if (enemy->hp > 0 && Engine::Collider::IsCircleOverlap(Position, 250, enemy->Position, enemy->CollisionRadius)){
                enemy->hp += 5;
                getPlayScene()->EffectGroup->AddNewObject(new HealEffect(enemy->Position.x, enemy->Position.y));
                //printf("healed enemy to hp %f\n", enemy->hp);
            }
        }
		OnExplode();
		// Remove all turret's reference to target.
		for (auto& it: lockedTurrets)
			it->Target = nullptr;
		for (auto& it: lockedBullets)
			it->Target = nullptr;
		getPlayScene()->EarnMoney(money);
		getPlayScene()->EnemyGroup->RemoveObject(objectIterator);
		AudioHelper::PlayAudio("explosion.wav");
	}
}
