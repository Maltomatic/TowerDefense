#include "EBullet.hpp"
#include "Collider.hpp"
#include "Turret.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"

PlayScene* EBullet::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
void EBullet::OnExplode(Turret* turret) {
}
EBullet::EBullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent) :
	Sprite(img, position.x, position.y), speed(speed), damage(damage), parent(parent) {
	Velocity = forwardDirection * speed * -1;
	Rotation = rotation;
	CollisionRadius = 4;
}
void EBullet::Update(float deltaTime) {
	Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	// Can be improved by Spatial Hash, Quad Tree, ...
	// However simply loop through all enemies is enough for this program.
	for (auto& it : scene->TowerGroup->GetObjects()) {
		Turret* turret = dynamic_cast<Turret*>(it);
		if (!turret->Visible)
			continue;
		if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, turret->Position, turret->CollisionRadius)) {
			OnExplode(turret);
			turret->Hit(damage);
			getPlayScene()->EBulletGroup->RemoveObject(objectIterator);
			return;
		}
	}
	// Check if out of boundary.
	if (!Engine::Collider::IsRectOverlap(Position - Size / 2, Position + Size / 2, Engine::Point(0, 0), PlayScene::GetClientSize()))
		getPlayScene()->EBulletGroup->RemoveObject(objectIterator);
}
