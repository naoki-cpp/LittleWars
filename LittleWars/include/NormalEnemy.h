#pragma once
#include "enemy.h"
#include "Circle.h"
#include "GraphicLoading.h"
class NormalEnemy :
	public Enemy,public Circle
{
public:
	NormalEnemy(std::shared_ptr<GraphicLoading> graph_loader, const lws::vector<double> &coordinate_, const lws::vector<double> &speed_, const lws::vector<int> & window, std::weak_ptr<GameControler> controler);
	virtual ~NormalEnemy(void);

	void Attacked(GameObject &HitObject)override;
private:
	NormalEnemy(NormalEnemy&);
	void Attack()override;
	const int kShotMachineGunInterval;
	int shot_machinegun_wait_timer_;
};