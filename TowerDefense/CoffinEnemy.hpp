#ifndef COFFINENEMY_HPP
#define COFFINENEMY_HPP
#include "Enemy.hpp"

class CoffinEnemy : public Enemy {
public:
	CoffinEnemy(int x, int y);
	void CreateBullet() override;
};
#endif // COFFINENEMY_HPP
