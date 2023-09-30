#ifndef UNATURRET_HPP
#define UNATURRET_HPP
#include "Turret.hpp"

class UnaTurret: public Turret {
public:
	static const int Price;
    UnaTurret(float x, float y);
    void CreateBullet() override;
    void OnExplode() override;
    void Draw() const override;
};
#endif // UNATURRET_HPP
