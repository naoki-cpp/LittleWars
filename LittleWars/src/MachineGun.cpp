#include "..\include\MachineGun.h"
MachineGun::MachineGun(std::shared_ptr<GraphicLoading> graph_loader,OffensiveType offensive_value, const lws::vector<double> &coordinate, const lws::vector<double> speed, const lws::vector<int> & window, std::weak_ptr<GameControler> controler) :
	GameObject(coordinate,graph_loader->GetGraphicPtr(MACHINEGUN)),
	Weapon(2,offensive_value,window, speed, graph_loader,controler),
	Rect(Point::size_,Point::coordinate_)
{
	attack_power_ = 5;
}

MachineGun::~MachineGun(void)
{
}

void MachineGun::Attacked(GameObject &HitObject) {
	hit_point_ -= HitObject.attack_power();
}

void MachineGun::Update()
{
	if (OutOfWindow() ||
		hit_point_ < 0) {
		Die(nullptr);
	}
	Move();
}

void MachineGun::Move() {
	Moving::Move();
}


void MachineGun::Draw()const {
	Living::Draw();
}