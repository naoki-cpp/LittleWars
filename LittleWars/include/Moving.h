#pragma once
#include "gameobject.h"
class Moving :
	public virtual GameObject
{
public:

	virtual ~Moving(void)
	{
	}
protected:
	virtual void Move()
	{
		coordinate_ += speed_;
	}

	Moving(const lws::vector<size_t> &window,const lws::vector<double> &speed):
		kWindow(window),
		speed_(speed) 
	{
	}
	bool OutOfWindow() {
		return (coordinate_.x_ > kWindow.x_ ||
			coordinate_.y_ > kWindow.y_ ||
			coordinate_.y_ < 0 ||
			coordinate_.x_ < 0);
	}
	const lws::vector<size_t> kWindow;
	lws::vector<double> speed()const{ return speed_; }
	lws::vector<double> speed_;
private:
	Moving(Moving&);
};

