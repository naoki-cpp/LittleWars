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
	bool CheckLineCrossing(const lws::vector<double> &p1, const lws::vector<double> &p2, const lws::vector<double> &q1, const lws::vector<double> &q2)const;
};