#include <allegro5/base.h>
#include <string>

#include "Group.hpp"
#include "Shovel.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
const int Shovel::Price = 0;
Shovel::Shovel(float x, float y) :
    // TODO 2 (2/8): You can imitate the 2 files: 'FreezeTurret.hpp', 'FreezeTurret.cpp' to create a new turret.
	Turret("play/dozer.png", x, y, Price, 1000000, 100, 1) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 10.0f / GetBitmapHeight();
	printf("shovel constructor\n");
}

void Shovel::CreateBullet(){
    return;
}

void Shovel::Hit(float damage){
    return;
}

void Shovel::OnExplode(){
    return;
}
