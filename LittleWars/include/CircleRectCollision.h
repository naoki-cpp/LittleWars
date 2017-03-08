#pragma once
#include "collision.h"
#include "Rect.h"
#include "Circle.h"

class CircleRectCollision :
	public Collision
{
public:

	CircleRectCollision(void)
	{
	}

	virtual ~CircleRectCollision(void)
	{
	}
	bool CollisionTest(const Shape& s1, const Shape& s2)const override;
private:
	template<typename T>
	T square(T x_)const { return x_*x_; }
	template<typename T>
	T InnerProduct(const lws::vector<T> vector1, const lws::vector<T> vector2)const { return (vector1.x_*vector2.x_ + vector1.y_*vector2.y_); }
	template<typename T>
	T OuterProduct(const lws::vector<T> vector1, const lws::vector<T> vector2)const { return (vector1.x_*vector2.y_ - vector1.y_*vector2.x_); }
	template<typename T>
	T VectorLength2(const lws::vector<T> vector)const { return InnerProduct(vector, vector); }

	bool VertexInCircle(const lws::vector<double> vertex[4], const Circle &circle)const;
	bool CircleAcrossRectangle(const lws::vector<double> vertex[4], const Circle &circle)const;
	bool CircleInRect(const lws::vector<double> vertex[4], const Circle &circle)const;
};

