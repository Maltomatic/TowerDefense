#include <string>

#include "BombEnemy.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Group.hpp"
#include "AudioHelper.hpp"
#include "EnBomb.hpp"

BombEnemy::BombEnemy(int x, int y) : Enemy("play/enemy-4.png", x, y, 25, 30, 2, 3, 30) {
    // TODO 2 (6/8): You can imitate the 2 files: 'NormalEnemy.hpp', 'NormalEnemy.cpp' to create a new enemy.
}

void BombEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EBulletGroup->AddNewObject(new EnBomb(Position , diff, rotation, this));
	AudioHelper::PlayAudio("ice.wav");
}
