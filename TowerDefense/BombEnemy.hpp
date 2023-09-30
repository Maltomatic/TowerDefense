#ifndef BOMBENEMY_HPP
#define BOMBENEMY_HPP
#include "Enemy.hpp"

class BombEnemy : public Enemy {
public:
	BombEnemy(int x, int y);
	void CreateBullet() override;
};
#endif // BOMBENEMY_HPP

