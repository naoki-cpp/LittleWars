#pragma once
#include "Shape.h"
class Collision
{
public:

	Collision(void)
	{
	}

	virtual ~Collision(void)
	{
	}
	//�����蔻��
	virtual bool CollisionTest(const Shape& s1, const Shape& s2)const = 0;/*true::collided false::not collided*/

};

