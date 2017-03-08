#pragma once
#include "collision.h"
class CircleCircleCollision :
	public Collision
{
public:

	CircleCircleCollision(void)
	{
	}

	virtual ~CircleCircleCollision(void)
	{
	}
	bool CollisionTest(const Shape &S1, const Shape &S2)const override;

private:
	template<class T>
	T square(const T &x_)const{
		return x_*x_;
	}
};

