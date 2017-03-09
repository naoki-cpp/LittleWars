#include "..\include\Missile.h"
#include "../include/ExplosionEffect.h"
#include "../include/ExplosionSound.h"
#include "../include/Enemy.h"

Missile::Missile(std::shared_ptr<GraphicLoading> graph_loader, OffensiveType offensive_value, const lws::Vector<double> &coordinate, const lws::Vector<double> &speed, double acceleration, double maxspeed, const lws::Vector<int> &window, bool homing_flag, std::weak_ptr<GameControler> controler) :
	GameObject(coordinate,graph_loader->GetGraphicPtr(GraphType::MISSILE)),
	HomingWeapon(5, offensive_value, window, speed, graph_loader, controler),
	Rect(Point::size_,Point::coordinate_),
	homing_flag_(homing_flag),
	kAcceleration(acceleration),
	kMaxSpeed(maxspeed),
	lock_on_sight_(graph_loader->GetGraphicPtr(GraphType::LOCK_ON_SIGHT))
{
	attack_power_ = 100;
}
void Missile::Update()
{
	if (hit_point_ < 0) {
		Die(std::make_shared<ExplosionEffect>(GetGraphFromLoader(GraphType::EXPLOSION), Point::coordinate_, Point::angle()));
	}
	else
	{
		if (Moving::OutOfWindow())
			Die(nullptr);
	}
	Move();
}
Missile::~Missile(void)
{
}
void Missile::Attacked(GameObject &HitObject) {
	hit_point_ -= HitObject.attack_power();
};

void Missile::Move() {
	std::weak_ptr<GameObject> object = targeted_object();
	if (!object.expired() && homing_flag_)
	{
		speed_ += GetUnitVector() * kAcceleration;
		lock_on_sight_->Draw(lws::Vector<double>(object.lock()->GetCoordinateX() + object.lock()->GetSizeX()/2, object.lock()->GetCoordinateY()), 0.0);
	}
	double theta = (speed_).GetArgument();
	if (speed_.Square() > kMaxSpeed*kMaxSpeed)
	{
		speed_ = lws::Vector<double>(cos(theta),sin(theta)) * kMaxSpeed;
	}
	Point::angle(theta);
	Moving::Move();
}

void Missile::Draw()const
{
	Weapon::Draw();
}
