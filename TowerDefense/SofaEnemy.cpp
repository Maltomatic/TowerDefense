#include <string>

#include "SofaEnemy.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Group.hpp"
#include "AudioHelper.hpp"
#include "EnBullet.hpp"

SofaEnemy::SofaEnemy(int x, int y) : Enemy("play/enemy-2.png", x, y, 20, 100, 0.7, 5, 20) {
	// Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
	// and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}

void SofaEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EBulletGroup->AddNewObject(new EnBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("laser.wav");
}
