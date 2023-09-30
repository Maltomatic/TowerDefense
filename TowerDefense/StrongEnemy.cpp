#include <string>

#include "StrongEnemy.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Group.hpp"
#include "AudioHelper.hpp"
#include "EnBullet.hpp"

StrongEnemy::StrongEnemy(int x, int y) : Enemy("play/enemy-3.png", x, y, 35, 25, 0.3, 20, 25) {
	// Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
	// and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}

void StrongEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EBulletGroup->AddNewObject(new EnBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("laser.wav");
}
