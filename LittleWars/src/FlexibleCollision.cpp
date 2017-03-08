#include "..\include\FlexibleCollision.h"
#include "..\include\CircleCircleCollision.h"
#include "..\include\CircleRectCollision.h"
#include "..\include\RectRectCollision.h"
#include "..\include\NullCollision.h"

FlexibleCollision::FlexibleCollision(void)
{
	m_ColTable[SHAPE_TYPE::CIRCLE_TYPE][SHAPE_TYPE::CIRCLE_TYPE] = std::make_unique<CircleCircleCollision>();
	m_ColTable[SHAPE_TYPE::CIRCLE_TYPE][SHAPE_TYPE::RECT_TYPE] = std::make_unique<CircleRectCollision>();
	m_ColTable[SHAPE_TYPE::CIRCLE_TYPE][SHAPE_TYPE::NULL_TYPE] = std::make_unique<NullCollision>();
	m_ColTable[SHAPE_TYPE::RECT_TYPE][SHAPE_TYPE::CIRCLE_TYPE] = std::make_unique<CircleRectCollision>();
	m_ColTable[SHAPE_TYPE::RECT_TYPE][SHAPE_TYPE::RECT_TYPE] = std::make_unique<RectRectCollision>();
	m_ColTable[SHAPE_TYPE::RECT_TYPE][SHAPE_TYPE::NULL_TYPE] = std::make_unique<NullCollision>();
	m_ColTable[SHAPE_TYPE::NULL_TYPE][SHAPE_TYPE::CIRCLE_TYPE] = std::make_unique<NullCollision>();
	m_ColTable[SHAPE_TYPE::NULL_TYPE][SHAPE_TYPE::RECT_TYPE] = std::make_unique<NullCollision>();
	m_ColTable[SHAPE_TYPE::NULL_TYPE][SHAPE_TYPE::NULL_TYPE] = std::make_unique<NullCollision>();
}
