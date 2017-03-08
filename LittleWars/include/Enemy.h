#pragma once
#include "Armed.h"
#include "Moving.h"
#include "Living.h"
#include "GameObject.h"
#include "ExplosionEffect.h"
class Enemy :
	public Armed, public Moving, virtual public GameObject
{
public:
	Enemy(int hit_point, const lws::vector<int> window, const lws::vector<double> &speed, std::weak_ptr<GameControler> controler, std::shared_ptr<GraphicLoading> graph_loader) :
		Armed(hit_point, graph_loader, controler),
		Moving(window, speed) {
		offensive_value_ = OffensiveType::ENEMY;
	}
	virtual ~Enemy(void) {};
	virtual void Update()override {
		Move();
		Attack();
		if (hit_point_ <= 0)Die(std::make_shared<ExplosionEffect>(GetGraphFromLoader(GraphType::EXPLOSION), coordinate_, angle()));
		if (OutOfWindow())Die(nullptr);
	}
	virtual void Draw()const override { Living::Draw(); }
	bool DisappearFlag()override { return Living::DisappearFlag(); }
protected:
	virtual void Attack()override = 0;
	virtual void Attacked(GameObject&)override {}
	virtual bool Targetable() { return true; }
};

