#pragma once
enum SHAPE_TYPE:size_t{
	CIRCLE_TYPE,
	RECT_TYPE,
	NULL_TYPE,
	SHAPE_NUM
};
class Shape
{
public:

	Shape(void)
	{}

	virtual ~Shape(void)
	{}

	virtual SHAPE_TYPE GetShapeType()const = 0;
};

