#pragma once
#include "Enemy.h"
#include "Circle.h"
class StrongEnemy :
	public Enemy,public Circle
{
public:
	StrongEnemy(const std::shared_ptr<GraphicLoading> graph_loader, const lws::vector<double> &coordinate_, const lws::vector<double> &speed_, const lws::vector<int> & window, std::weak_ptr<GameControler> controler);
	virtual ~StrongEnemy();

	void NearestEnemy(std::shared_ptr<GameObject>)override;

	void Attacked(GameObject &HitObject)override;
private:
	void Attack()override;
	const int kShotMachineGunInterval;
	int shot_machinegun_wait_timer_;
	std::weak_ptr<GameObject> nearest_enemy_;
};