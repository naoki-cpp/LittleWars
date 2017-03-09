#pragma once
#include "Enemy.h"
#include "GraphicLoading.h"
class ExtremeEnemy :
	public Enemy
{
public:
	ExtremeEnemy(const std::shared_ptr<GraphicLoading> graph_loader, const lws::Vector<double> &coordinate, const lws::Vector<double> &speed, const lws::Vector<int> & window, std::weak_ptr<GameControler> controler);
	virtual ~ExtremeEnemy();
private:
	void Attack()override;
};