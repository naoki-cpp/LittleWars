#pragma once
#include "gameobject.h"
#include "Effect.h"
#include "GameControler.h"
#include "GraphicLoading.h"


class Living :
	public virtual GameObject
{
public:
	virtual ~Living(void)
	{}

	virtual void Attacked(GameObject &HitObject)override
	{
		hit_point_ -= HitObject.attack_power();
	}

	bool DisappearFlag()override { return (living_mode_ == LIVING_FLAG::DEATH); }
	virtual void Draw()const override {
		switch (living_mode_)
		{
		case LIVING_FLAG::ALIVE:
			GameObject::Draw();
			break;
		case LIVING_FLAG::DEATH:
			break;
		default:
			break;
		}
	}

	int GetHitPoint()const { return hit_point_; }
protected:
	int hit_point_;
	Living(int HitPoint, std::shared_ptr<GraphicLoading> graph_loader, std::weak_ptr<GameControler> controler) :
		controler_(controler),
		graph_loader_(graph_loader),
		hit_point_(HitPoint),
		living_mode_(LIVING_FLAG::ALIVE)
	{
	}

	std::shared_ptr<GraphicElement> GetGraphFromLoader(GraphType type) {
		return graph_loader_->GetGraphicPtr(type);
	}

	std::shared_ptr<GraphicLoading> GetLoader() {
		return graph_loader_;
	}

	void Die(std::shared_ptr<Effect> effect) {
		if (living_mode_ != LIVING_FLAG::DEATH)
		{
			living_mode_ = LIVING_FLAG::DEATH;
			if (effect)
			{
				controler_.lock()->AddObject(effect);
			}
		}
	}

	std::weak_ptr<GameControler> controler_;
private:
	enum class LIVING_FLAG
	{
		ALIVE,
		DEATH
	};
	std::shared_ptr<GraphicLoading> graph_loader_;
	LIVING_FLAG living_mode_;
	Living(Living&);
};