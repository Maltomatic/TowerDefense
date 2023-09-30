#ifndef ENBULLET_HPP
#define ENBULLET_HPP
#include "EBullet.hpp"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class EnBullet : public EBullet {
public:
	explicit EnBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* turret) override;
};
#endif // ENBULLET_HPP
