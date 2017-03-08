#include "..\include\ExtremeEnemy.h"
#include "../include/ExplosionEffect.h"



ExtremeEnemy::ExtremeEnemy(const std::shared_ptr<GraphicLoading> graph_loader, const lws::vector<double> &coordinate, const lws::vector<double> &speed, const lws::vector<int> & window, std::weak_ptr<GameControler> controler) :
	GameObject(coordinate,graph_loader->GetGraphicPtr(GraphType::EXTREME_ENEMY)),
	Enemy(100, window, speed, controler, graph_loader)
{
}


ExtremeEnemy::~ExtremeEnemy()
{
}

void ExtremeEnemy::Attack()
{
}