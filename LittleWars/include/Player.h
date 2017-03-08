#pragma once
#include "Living.h"
#include "Armed.h"
#include "Moving.h"
#include "Circle.h"
#include "GameObject.h"
#include "GraphicLoading.h"
class Player :
	public Armed, public Moving, public Circle
{
public:
	Player(const std::shared_ptr<GraphicLoading> graph_loader, const lws::vector<double>& coordinate_, const lws::vector<double>& speed_, int kShotMissileInterval, int kShotMachineGunInterval, const lws::vector<int>& window, int * key, std::weak_ptr<GameControler> controler);
	~Player(void);
	void Update()override;
	void Attacked(GameObject &HitObject)override;
	void Draw()const override;
	bool DisappearFlag()override { return Living::DisappearFlag(); }
private:
	void Move()override;
	void Attack()override;
	int* key_input_;
	int shot_missile_timer_, shot_machinegun_timer_ ,homing_timer_;
	lws::vector<double> default_speed_;

	bool homing_flag_;
	const int kShotMissileInterval, kShotMachineGunInterval, kHomingInterval;
	bool Targetable()override { return true; }
};