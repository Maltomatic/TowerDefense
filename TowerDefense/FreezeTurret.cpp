#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "FireBullet.hpp"
#include "Group.hpp"
#include "FreezeTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
const int FreezeTurret::Price = 80;
FreezeTurret::FreezeTurret(float x, float y) :
	// TODO 2 (2/8): You can imitate the 2 files: 'FreezeTurret.hpp', 'FreezeTurret.cpp' to create a new turret.
	Turret("play/turret-4.png", x, y, Price, 1.0, 15, 35) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void FreezeTurret::CreateBullet() {
	Engine::Point diff = Engine::Point(1, 0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->BulletGroup->AddNewObject(new FireBullet(Position, diff, rotation, this));
	AudioHelper::PlayAudio("ice.wav");
}
