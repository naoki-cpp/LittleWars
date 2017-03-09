#pragma once
#include "lws.h"
class Point
{
public:
	Point(const lws::Vector<double> &Coordinate, const lws::Vector<int> &Size) :
		coordinate_(Coordinate),
		size_(Size),
		angle_(0.0)
	{
	}
	Point() {}

	virtual ~Point()
	{
	}

	double GetCoordinateX()const{ return coordinate_.x_; }
	double GetCoordinateY()const{ return coordinate_.y_; }

	size_t GetSizeX()const{ return size_.x_; }
	size_t GetSizeY()const{ return size_.y_; }

	lws::Vector<double> GetCoordinate()const{ return coordinate_; }
	lws::Vector<int> GetSize()const{ return size_; }

protected:
	lws::Vector<double> coordinate_;
	lws::Vector<int> size_;
	void angle(const double angle) { angle_ = angle; }
	double angle()const { return angle_; }
private:
	double angle_;
};