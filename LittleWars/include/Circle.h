#pragma once
#include "shape.h"
#include "lws.h"

class Circle :
	public virtual Shape
{
public:

	Circle(lws::vector<int>& size, lws::vector<double>& coordinate):
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
	lws::vector<int>& size_;
	lws::vector<double>& coordinate_;
};

