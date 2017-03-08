#include "collision.h"
#include <vector>
#include <memory>
class FlexibleCollision :
	public Collision
{
public:

	FlexibleCollision(void);
	virtual ~FlexibleCollision(void)
	{
	}
	bool CollisionTest(const Shape& s1, const Shape& s2)const{
		return (m_ColTable[s1.GetShapeType()][s2.GetShapeType()])->CollisionTest(s1, s2);
	}
private:
	std::unique_ptr<Collision> m_ColTable[SHAPE_TYPE::SHAPE_NUM][SHAPE_TYPE::SHAPE_NUM];
};