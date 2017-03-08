#pragma once
#include "Collision.h"
class NullCollision :
	public Collision
{
public:

	NullCollision()
	{
	}

	~NullCollision()
	{
	}

	bool CollisionTest(const Shape& s1, const Shape& s2)const override { return false; }

};

