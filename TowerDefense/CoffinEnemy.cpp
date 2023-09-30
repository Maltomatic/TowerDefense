#include <string>

#include "CoffinEnemy.hpp"

CoffinEnemy::CoffinEnemy(int x, int y) : Enemy("play/coffin_small.png", x, y, 25, 25, 100, 2, 5) {
    // TODO 2 (6/8): You can imitate the 2 files: 'NormalEnemy.hpp', 'NormalEnemy.cpp' to create a new enemy.
}

void CoffinEnemy::CreateBullet() {
	return;
}
