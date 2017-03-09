#include "../include/CircleRectCollision.h"
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>

bool CircleRectCollision::CollisionTest(const Shape& s1, const Shape& s2)const{
	const Rect* rect1 = nullptr;
	const Circle* circle2 = nullptr;
	if (s1.GetShapeType() == SHAPE_TYPE::RECT_TYPE && s2.GetShapeType() == SHAPE_TYPE::CIRCLE_TYPE) {
		rect1 = dynamic_cast<const Rect*>(&s1);
		circle2 = dynamic_cast<const Circle*>(&s2);
	}
	if (s1.GetShapeType() == SHAPE_TYPE::CIRCLE_TYPE && s2.GetShapeType() == SHAPE_TYPE::RECT_TYPE) {
		rect1 = dynamic_cast<const Rect*>(&s2);
		circle2 = dynamic_cast<const Circle*>(&s1);
	}
	if (rect1 && circle2){
		lws::Vector<double> vertex[4] = {
			lws::Vector<double>(rect1->GetLeft(), rect1->GetTop()),
			lws::Vector<double>(rect1->GetLeft(), rect1->GetBottom()),
			lws::Vector<double>(rect1->GetRight(), rect1->GetBottom()),
			lws::Vector<double>(rect1->GetRight(), rect1->GetTop())
		};

		if (VertexInCircle(vertex, (*circle2)) || CircleAcrossRectangle(vertex, (*circle2)) || CircleInRect(vertex, (*circle2))){
			return true;
		}
		else{
			return false;
		}
	}
	return false;
}
bool CircleRectCollision::VertexInCircle(const lws::Vector<double> vertex[4], const Circle &circle)const{
	for (size_t i = 0; i < 4; ++i)
	{
		if ((square(vertex[i].x_ - circle.GetCenterX()) + square(vertex[i].y_ - circle.GetCenterY()))
			< square(circle.GetRadious()))
		{
			return true;
		}
	}
	return false;
}

bool CircleRectCollision::CircleAcrossRectangle(const lws::Vector<double> vertex[4], const Circle &circle)const{
	lws::Vector<double>CircleCenter = lws::Vector<double>(circle.GetCenterX(), circle.GetCenterY());
	for (size_t i = 0; i < 4; ++i)
	{
		lws::Vector<double> pq = vertex[(i+1)%4] - vertex[i];
		lws::Vector<double> pm = CircleCenter - vertex[i];
		double inner = InnerProduct(pq, pm);
		double pqd2 = VectorLength2(pq);
		double k = inner / pqd2;
		if (0 <= k && k <= 1){
			if (VectorLength2(pm) - square(inner) / pqd2 < square(circle.GetRadious())){
				return true;
			}
		}
	}
	return false;
}
bool CircleRectCollision::CircleInRect(const lws::Vector<double> vertex[4], const Circle &circle)const{
	lws::Vector<double>CircleCenter = lws::Vector<double>(circle.GetCenterX(), circle.GetCenterY());
	double theta[2];

	for (size_t i = 0; i < 2; ++i){
		lws::Vector<double> pp, pm;
		double inner, outer;
		pp = vertex[i * 2] - vertex[3 - i * 2];//0,3;2,1
		pm = CircleCenter - vertex[i];

		inner = InnerProduct(pp, pm);
		outer = OuterProduct(pp, pm);

		theta[i] = atan2(outer, inner);
	}

	if (0 <= theta[0] && theta[0] <= M_PI &&
		0 <= theta[1] && theta[1] <= M_PI){
		return true;
	}

	return false;

}