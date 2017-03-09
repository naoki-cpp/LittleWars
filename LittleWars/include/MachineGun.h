#pragma once
#include "weapon.h"
#include "Moving.h"
#include "GameObject.h"
#include "Rect.h"
class MachineGun :
	public Weapon, public Rect
{
public:
	MachineGun(std::shared_ptr<GraphicLoading> graph_loader, OffensiveType offensive_value, const lws::Vector<double> &coordinate, const lws::Vector<double> speed, const lws::Vector<int> & window, std::weak_ptr<GameControler> controler);
	virtual ~MachineGun(void);
	void Attacked(GameObject &HitObject)override;
	void Update()override;
	void Draw()const override;

private:
	void Move()override;
};

