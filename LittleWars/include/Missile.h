#pragma once
#include "HomingWeapon.h"
#include "Moving.h"
#include "GameObject.h"
#include "Rect.h"
#include "SoundControl.h"
#include "GraphicLoading.h"
class Missile :
	public HomingWeapon, public Rect
{
public:
	Missile(std::shared_ptr<GraphicLoading> loader, OffensiveType offensive_value, const lws::vector<double> &coordinate_, const lws::vector<double> &speed_, double acceleration, double maxspeed, const lws::vector<int> & window, bool homing_flag, std::weak_ptr<GameControler> controler);
	void Update()override;
	void Attacked(GameObject &HitObject)override;
	void NearestEnemy(std::shared_ptr<GameObject> object)override { targeted_object(object); }
	virtual ~Missile(void);
private:
	void Move()override;
	void Draw()const override;
	const double kAcceleration;
	const double kMaxSpeed;
	bool homing_flag_;
	std::shared_ptr<GraphicElement> lock_on_sight_;
};

