#include <string>

#include "NormalEnemy.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Group.hpp"
#include "AudioHelper.hpp"
#include "EnBullet.hpp"

NormalEnemy::NormalEnemy(int x, int y) : Enemy("play/enemy-1.png", x, y, 25, 50, 1, 3, 15) {
    // TODO 2 (6/8): You can imitate the 2 files: 'NormalEnemy.hpp', 'NormalEnemy.cpp' to create a new enemy.
}

void NormalEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EBulletGroup->AddNewObject(new EnBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("laser.wav");
}
