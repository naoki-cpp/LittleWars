#include <string>
#include "DxLib/DxLib.h"
#include "../include/Player.h"
#include "../include/Missile.h"
#include "../include/ExplosionEffect.h"
#include "../include/MachineGun.h"
#include "../include/GraphicLoading.h"

Player::Player(std::shared_ptr<GraphicLoading> graph_loader, const lws::Vector<double> &coordinate, const lws::Vector<double> &speed, int kShotMissileInterval, int kShotMachineGunInterval, const lws::Vector<int> &window, int *key, std::weak_ptr<GameControler> controler) :
	GameObject(coordinate,graph_loader->GetGraphicPtr(GraphType::PLAYER)),
	Armed(100, graph_loader, controler),
	Moving(window, lws::Vector<double>(0.0, 0.0)),
	Circle(Point::size_,Point::coordinate_),
	default_speed_(speed),
	key_input_(key),
	kShotMissileInterval(kShotMissileInterval),
	kShotMachineGunInterval(kShotMachineGunInterval),
	shot_missile_timer_(0),
	shot_machinegun_timer_(0),
	homing_flag_(true),
	homing_timer_(0),
	kHomingInterval(30)
{
	offensive_value_ = OffensiveType::FRIENDLY;
	attack_power_ = 10;
}
Player::~Player(void)
{
}
void Player::Draw()const {
	DrawFormatString(0, 80, GetColor(255, 255, 255), "Homing->%s", (homing_flag_ ? "ON" : "OFF"));
	Living::Draw();
}
void Player::Attack() {
	if ((key_input_[KEY_INPUT_Z] > 0) && (shot_missile_timer_ < 0)) {
		shot_missile_timer_ = kShotMissileInterval;
		std::shared_ptr<GameControler> controler = controler_.lock();
		controler->AddObject(std::make_shared<Missile>(GetLoader(), OffensiveType::FRIENDLY, lws::Vector<double>(Point::coordinate_.x_, Point::coordinate_.y_ - 32), lws::Vector<double>(0.0, -4.0 + speed_.y_), 0.6, 6.0, kWindow, homing_flag_, controler_));
	}
	else
	{
		--shot_missile_timer_;
	}
	if ((key_input_[KEY_INPUT_X] > 0) && (shot_machinegun_timer_ < 0))
	{
		shot_machinegun_timer_ = kShotMachineGunInterval;
		std::shared_ptr<GameControler> controler = controler_.lock(); 
		controler->AddObject(std::make_shared<MachineGun>(GetLoader(), OffensiveType::FRIENDLY, lws::Vector<double>(Point::coordinate_.x_ + (graphic_->GetGraphSizeX() / 2), Point::coordinate_.y_ - 32), lws::Vector<double>(0.0, -6.0 + speed_.y_), kWindow, controler_));
		controler->AddObject(std::make_shared<MachineGun>(GetLoader(), OffensiveType::FRIENDLY, lws::Vector<double>(Point::coordinate_.x_ - (graphic_->GetGraphSizeX() / 2), Point::coordinate_.y_ - 32), lws::Vector<double>(0.0, -6.0 + speed_.y_), kWindow, controler_));

	}
	else
	{
		--shot_machinegun_timer_;
	}
	if (key_input_[KEY_INPUT_A] > 0 && homing_timer_ <= 0) {
		homing_flag_ = (!homing_flag_);
		homing_timer_ = kHomingInterval;
	}
	else
	{
		--homing_timer_;
	}
}
void Player::Attacked(GameObject &HitObject) {
	Living::Attacked(HitObject);
}
void Player::Move() {
	lws::Vector<double> Speed = ((key_input_[KEY_INPUT_LSHIFT]) > 0 ? lws::Vector<double>(default_speed_.x_ / 2, default_speed_.y_ / 2) : default_speed_);
	speed_.y_ = (-((key_input_[KEY_INPUT_UP]) > 0) + ((key_input_[KEY_INPUT_DOWN]) > 0))*Speed.y_;
	speed_.x_ = (((key_input_[KEY_INPUT_RIGHT]) > 0) - ((key_input_[KEY_INPUT_LEFT]) > 0))*Speed.x_;
	Moving::Move();

	if (Point::coordinate_.x_ < 0)Point::coordinate_.x_ = 0;
	if (Point::coordinate_.y_ < 0)Point::coordinate_.y_ = 0;
	if (Point::coordinate_.y_ > kWindow.y_)Point::coordinate_.y_ = kWindow.y_;
	if (Point::coordinate_.x_ > kWindow.x_)Point::coordinate_.x_ = kWindow.x_;
	
}

void Player::Update()
{
	if (hit_point_ <= 0)Die(std::make_shared<ExplosionEffect>(GetGraphFromLoader(GraphType::EXPLOSION), Point::coordinate_, angle()));
	Move();
	Attack();
}
