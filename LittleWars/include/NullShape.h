#pragma once
#include "Shape.h"
class NullShape :
	public virtual Shape
{
public:

	NullShape()
	{
	}

	virtual ~NullShape(void)
	{
	}
	SHAPE_TYPE GetShapeType()const override { return SHAPE_TYPE::NULL_TYPE; }
};

