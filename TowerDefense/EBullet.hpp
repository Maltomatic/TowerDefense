#ifndef EBULLET_HPP
#define EBULLET_HPP
#include <string>

#include "Sprite.hpp"

class Enemy;
class PlayScene;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class EBullet : public Engine::Sprite {
protected:
	float speed;
	float damage;
	Enemy* parent;
	PlayScene* getPlayScene();
	virtual void OnExplode(Turret* turret);
public:
	Turret* Target = nullptr;
	explicit EBullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	virtual void Update(float deltaTime) override;
};
#endif // EBULLET_HPP
