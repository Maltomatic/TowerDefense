#include <string>

#include "Vampire.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Group.hpp"
#include "AudioHelper.hpp"
#include "EnBullet.hpp"
#include "CoffinEnemy.hpp"

Vampire::Vampire(int x, int y) : Enemy("play/vampire.png", x, y, 25, 25, 1.2, 4, 50) {
    spawnCD = cooldown*2;
    spX = x;
    spY = y;
}

void Vampire::CreateBullet() {
	Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EBulletGroup->AddNewObject(new EnBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("laser.wav");
	canSpawn++;
	if(canSpawn == 2){
        spawn();
        canSpawn = 0;
	}
}

void Vampire::spawn(){
    int i;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int nx, ny;
    Enemy* enemy;
    for(i = 0; i < 4; i++){
        nx = spX+dx[i]*PlayScene::BlockSize;
        ny = spY+dy[i]*PlayScene::BlockSize;
        if(ny < 0 || ny > 5*PlayScene::BlockSize) continue;
        getPlayScene()->EnemyGroup->AddNewObject(enemy = new CoffinEnemy(nx, ny));
    }
}
