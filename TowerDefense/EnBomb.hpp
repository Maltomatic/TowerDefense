#ifndef ENBOMB_HPP
#define ENBOMB_HPP
#include "EBullet.hpp"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class EnBomb : public EBullet {
public:
	explicit EnBomb(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* turret) override;
};
#endif // ENBOMB_HPP
