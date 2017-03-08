#pragma once
#include "lws.h"
class Point
{
public:
	Point(const lws::vector<double> &Coordinate, const lws::vector<int> &Size) :
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

	lws::vector<double> GetCoordinate()const{ return coordinate_; }
	lws::vector<int> GetSize()const{ return size_; }

protected:
	lws::vector<double> coordinate_;
	lws::vector<int> size_;
	void angle(const double angle) { angle_ = angle; }
	double angle()const { return angle_; }
private:
	double angle_;
};