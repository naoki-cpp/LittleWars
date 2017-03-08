#include "../include/CircleCircleCollision.h"
#include "../include/Circle.h"

bool CircleCircleCollision::CollisionTest(const Shape &S1, const Shape &S2)const{
	const Circle* circle1 = dynamic_cast<const Circle*>(&S1);
	const Circle* circle2 = dynamic_cast<const Circle*>(&S2);
	if ((square(circle1->GetCenterX() - circle2->GetCenterX()) + square(circle1->GetCenterY() - circle2->GetCenterY()))
		< square(circle1->GetRadious() + circle2->GetRadious()))
	{
		return true;
	}
	else{
		return false;
	}
}