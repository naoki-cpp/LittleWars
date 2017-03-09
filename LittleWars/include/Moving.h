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

	Moving(const lws::Vector<size_t> &window,const lws::Vector<double> &speed):
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
	const lws::Vector<size_t> kWindow;
	lws::Vector<double> speed()const{ return speed_; }
	lws::Vector<double> speed_;
private:
	Moving(Moving&);
};

