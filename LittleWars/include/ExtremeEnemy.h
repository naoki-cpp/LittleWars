#pragma once
#include "Enemy.h"
#include "GraphicLoading.h"
class ExtremeEnemy :
	public Enemy
{
public:
	ExtremeEnemy(const std::shared_ptr<GraphicLoading> graph_loader, const lws::vector<double> &coordinate, const lws::vector<double> &speed, const lws::vector<int> & window, std::weak_ptr<GameControler> controler);
	virtual ~ExtremeEnemy();
private:
	void Attack()override;
};