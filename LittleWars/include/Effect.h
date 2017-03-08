#pragma once
#include "Task.h"
#include "GameObject.h"
class Effect:public GameObject
{
public:

	virtual ~Effect()
	{
	}
	virtual void Draw()const override {
		graphic_->Draw(coordinate_, angle(), effect_count_);
	}
	virtual bool DisappearFlag()override {
		return (effect_count_ >= graphic_->GetElementCount());
	}
protected:
	Effect(std::shared_ptr<GraphicElement> graphic,const lws::vector<int> &coordinate, const double angle) :
		GameObject(coordinate,graphic),
		effect_count_(0)
	{}
	void InclimentCounter() {
		if (effect_count_ < graphic_->GetElementCount()) {
			effect_count_++;
		}
	}
private:
	size_t effect_count_;
};

