#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Enemy.hpp"

class Vampire : public Enemy {
    float spawnCD;
    int canSpawn;
    int spX;
    int spY;
public:
	Vampire(int x, int y);
	void CreateBullet() override;
	void spawn();
};
#endif // VAMPIRE_HPP
