#include "..\include\StrongEnemy.h"
#include "..\include\ExplosionEffect.h"
#include "..\include\MachineGun.h"

StrongEnemy::StrongEnemy(std::shared_ptr<GraphicLoading> graph_loader, const lws::vector<double> &coordinate, const lws::vector<double> &speed, const lws::vector<int> & window, std::weak_ptr<GameControler> controler) :
	GameObject(coordinate,graph_loader->GetGraphicPtr(GraphType::STRONG_ENEMY)),
	Enemy(400, window, speed, controler, graph_loader),
	Circle(Point::size_, Point::coordinate_),
	kShotMachineGunInterval(20),
	shot_machinegun_wait_timer_(0),
	nearest_enemy_()
{
	attack_power_ = 5;
}

StrongEnemy::~StrongEnemy()
{
}

void StrongEnemy::Attack() {
	if (shot_machinegun_wait_timer_ < 0)
	{
		shot_machinegun_wait_timer_ = kShotMachineGunInterval;
		std::shared_ptr<GameControler> controler = controler_.lock();
		if (!nearest_enemy_.expired())
		{
			double argument = (nearest_enemy_.lock()->GetCoordinate() - Point::coordinate_).GetArgument();
			controler->AddObject(std::make_shared<MachineGun>(GetLoader(), OffensiveType::ENEMY, lws::vector<double>(Point::coordinate_.x_, Point::coordinate_.y_ + 32), lws::vector<double>(2.0*cos(argument), 2.0*sin(argument)), kWindow, controler_));
		}
		else {
			controler->AddObject(std::make_shared<MachineGun>(GetLoader(), OffensiveType::ENEMY, lws::vector<double>(Point::coordinate_.x_, Point::coordinate_.y_ + 32), lws::vector<double>(0.0, 2.0 + speed_.y_), kWindow, controler_));
		}
	}
	else
	{
		--shot_machinegun_wait_timer_;
	}

}

void StrongEnemy::NearestEnemy(std::shared_ptr<GameObject> object)
{
	nearest_enemy_ = object;
}
void StrongEnemy::Attacked(GameObject &HitObject)
{
	if (HitObject.offensive_value() == OffensiveType::FRIENDLY) {
		controler_.lock()->AddScore(HitObject.attack_power());
	}
	Living::Attacked(HitObject);
}
