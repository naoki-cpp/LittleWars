#pragma once
#include <memory>
#include "GraphicElement.h"
#include "Task.h"
#include "Shape.h"
#include "Point.h"

enum class OffensiveType
{
	ENEMY = -1,
	NEUTRAL,
	FRIENDLY,
};

class GameObject :public Task,public Point,public virtual Shape
{
protected:
	GameObject(const lws::Vector<double> &coordinate,std::shared_ptr<GraphicElement> &graphic) :
		Point(coordinate, lws::Vector<int>(graphic->GetGraphSizeX(),graphic->GetGraphSizeY())),
		graphic_(graphic),
		attack_power_(0),
		offensive_value_(OffensiveType::NEUTRAL)
	{}
	int attack_power_;
	std::shared_ptr<GraphicElement> graphic_;
	//“G‘Î’l:ˆÙ•„†‚ÌÒ“¯m‚Í“G
	OffensiveType offensive_value_;
private:
	GameObject(GameObject&);
public:
	virtual ~GameObject(void)
	{}
	virtual void Update()override {};
	virtual void Draw()const {
		graphic_->Draw(coordinate_,Point::angle());
	};
	virtual bool DisappearFlag() { return false; };
	virtual void NearestEnemy(std::shared_ptr<GameObject> object) {}
	//UŒ‚‚³‚ê‚½
	virtual void Attacked(GameObject& object) {}
	//ƒ^[ƒQƒbƒg‚Å‚«‚é‚©‚Ç‚¤‚©
	virtual bool Targetable() { return false; }
	int attack_power()const { return attack_power_; }
	//“G‘Î’l‚ğ•Ô‚·
	OffensiveType offensive_value()const { return offensive_value_; }
	
};
