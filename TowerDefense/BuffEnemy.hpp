#ifndef BUFFENEMY_HPP
#define BUFFENEMY_HPP
#include "Enemy.hpp"

class BuffEnemy : public Enemy {
public:
	BuffEnemy(int x, int y);
	void Hit(float damage) override;
};
#endif // NORMALENEMY_HPP
