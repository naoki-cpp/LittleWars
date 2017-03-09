#pragma once
#include "shape.h"
#include "lws.h"

class Rect :
	public virtual Shape
{
public:

	Rect(lws::Vector<int>& size, lws::Vector<double>& coordinate):
		size_(size),
		coordinate_(coordinate)
	{
	}

	virtual ~Rect(void)
	{
	}
	SHAPE_TYPE GetShapeType()const override{ return SHAPE_TYPE::RECT_TYPE; }

	double GetTop()const{ return coordinate_.y_ - size_.y_ / 2; }
	double GetLeft()const{ return coordinate_.x_ - size_.x_ / 2; }
	double GetBottom()const{ return coordinate_.y_ + size_.y_ / 2; }
	double GetRight()const{ return coordinate_.x_ + size_.x_ / 2; }

	double GetCenterX()const{ return coordinate_.x_; }
	double GetCenterY()const{ return coordinate_.y_; }

private:
	lws::Vector<int>& size_;
	lws::Vector<double>& coordinate_;
};

