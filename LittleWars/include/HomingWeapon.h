#pragma once
#include "weapon.h"
class HomingWeapon :
	public Weapon
{
public:

	HomingWeapon(int hit_point, OffensiveType offensive_value, const lws::Vector<int> &window, const lws::Vector<double> &speed, std::shared_ptr<GraphicLoading> graph_loader, std::weak_ptr<GameControler> controler) :
		Weapon(hit_point, offensive_value, window, speed, graph_loader, controler),
		targeted_object_()
	{
	}

	virtual ~HomingWeapon(void)
	{
	}
protected:
	std::weak_ptr<GameObject> targeted_object()const {
		return targeted_object_;
	}

	void targeted_object(std::weak_ptr<GameObject> object) {
		targeted_object_ = object;
	}
	const lws::Vector<double> GetUnitVector()const {
		if (!targeted_object_.expired())
		{
			std::shared_ptr<GameObject> object = targeted_object_.lock();
			if (object)
			{
				double theta = -((object->GetCoordinate() - coordinate_).GetArgument());
				return (lws::Vector<double>(cos(theta), -sin(theta)));
			}
		}
		return (lws::Vector<double>(0.0, 0.0));
	}
private:
	std::weak_ptr<GameObject> targeted_object_;
};