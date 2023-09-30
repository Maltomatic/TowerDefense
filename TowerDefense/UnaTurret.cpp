#include <allegro5/base.h>
#include <allegro5/allegro_primitives.h>
#include <string>
#include <cmath>
#include <random>
#include <vector>
#include <utility>

#include "Group.hpp"
#include "UnaTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "AudioHelper.hpp"
#include "ExplosionEffect.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "Collider.hpp"
#include "GameEngine.hpp"
const int UnaTurret::Price = 70;
UnaTurret::UnaTurret(float x, float y) :
    // TODO 2 (2/8): You can imitate the 2 files: 'FreezeTurret.hpp', 'FreezeTurret.cpp' to create a new turret.
	Turret("play/turret-5.png", x, y, Price, 100, 1, 40) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}

void UnaTurret::CreateBullet(){
    return;
}

void UnaTurret::OnExplode(){
    getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect(Position.x, Position.y));
    AudioHelper::PlayAudio("shockwave.ogg");
	//printf("exploded properly\n");
	// destroy all enemies in radius 250 ////TODO
	PlayScene* scene = getPlayScene();
	for(auto it: scene->EnemyGroup->GetObjects()){
        Enemy* enemy = dynamic_cast<Enemy*>(it);
		if (!enemy->Visible)
			continue;
		if (Engine::Collider::IsCircleOverlap(Position, 250, enemy->Position, enemy->CollisionRadius)) {
			enemy->Hit(enemy->hp);
		}
	}
}
void UnaTurret::Draw() const {
	/*if (Preview) {
		al_draw_filled_circle(Position.x, Position.y, CollisionRadius, al_map_rgba(0, 255, 0, 50));
	}*/
	Sprite::Draw();
	if (PlayScene::DebugMode) {
		// Draw collision radius.
		al_draw_circle(Position.x, Position.y, CollisionRadius, al_map_rgb(255, 0, 0), 2);
		al_draw_circle(Position.x, Position.y, 250, al_map_rgb(255, 128, 0), 2);
	}
}
