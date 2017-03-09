#include "..\include\ExtremeEnemy.h"
#include "../include/ExplosionEffect.h"



ExtremeEnemy::ExtremeEnemy(const std::shared_ptr<GraphicLoading> graph_loader, const lws::Vector<double> &coordinate, const lws::Vector<double> &speed, const lws::Vector<int> & window, std::weak_ptr<GameControler> controler) :
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