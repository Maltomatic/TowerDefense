#include <allegro5/base.h>
#include <string>

#include "Group.hpp"
#include "WallTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
const int WallTurret::Price = 60;
WallTurret::WallTurret(float x, float y) :
    // TODO 2 (2/8): You can imitate the 2 files: 'FreezeTurret.hpp', 'FreezeTurret.cpp' to create a new turret.
	Turret("play/burgerBIG.png", x, y, Price, 1000000, 100, 40) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 10.0f / GetBitmapHeight();
}

void WallTurret::CreateBullet(){
    return;
}
