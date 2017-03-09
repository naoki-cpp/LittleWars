#pragma once
#include "living.h"
#include "Moving.h"
#include "GameControler.h"
class Weapon :
	public Living, public Moving
{
public:

	virtual ~Weapon(void)
	{
	}
	virtual void Draw()const override { Living::Draw(); }
	bool DisappearFlag()override { return Living::DisappearFlag(); }
	virtual void Move()override { Moving::Move(); }
	virtual void Attacked(GameObject& HitObject)override { Living::Attacked(HitObject); }
protected:
	Weapon(int hit_point, OffensiveType offensive_value, const lws::Vector<int> &window, const lws::Vector<double> &speed, std::shared_ptr<GraphicLoading> graph_loader, std::weak_ptr<GameControler> controler) :
		Living(hit_point, graph_loader, controler),
		Moving(window, speed)
	{
		offensive_value_ = offensive_value;
	}
private:
	Weapon(Weapon&);
};