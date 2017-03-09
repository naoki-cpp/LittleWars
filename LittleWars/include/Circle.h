#pragma once
#include "shape.h"
#include "lws.h"

class Circle :
	public virtual Shape
{
public:

	Circle(lws::Vector<int>& size, lws::Vector<double>& coordinate):
		size_(size),
		coordinate_(coordinate)
	{
	}

	virtual ~Circle(void)
	{
	}
	virtual SHAPE_TYPE GetShapeType()const override{ return SHAPE_TYPE::CIRCLE_TYPE; }
	double GetRadious()const{ return size_.x_; }
	double GetCenterX()const{ return coordinate_.x_; }
	double GetCenterY()const{ return coordinate_.y_; }
private:
	lws::Vector<int>& size_;
	lws::Vector<double>& coordinate_;
};

