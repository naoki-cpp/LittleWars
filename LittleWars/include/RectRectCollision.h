#pragma once
#include "collision.h"
#include "lws.h"

class RectRectCollision :
	public Collision
{
public:

	RectRectCollision(void)
	{}

	virtual ~RectRectCollision(void)
	{}

	bool CollisionTest(const Shape& s1, const Shape& s2)const override;
private:
	bool CheckLineCrossing(const lws::Vector<double> &p1, const lws::Vector<double> &p2, const lws::Vector<double> &q1, const lws::Vector<double> &q2)const;
};