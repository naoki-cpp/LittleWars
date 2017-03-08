#include "../include/RectRectCollision.h"
#include "../include/Rect.h"

bool RectRectCollision::CollisionTest(const Shape& s1, const Shape& s2)const{
	const Rect* rect1 = dynamic_cast<const Rect*>(&s1);
	const Rect* rect2 = dynamic_cast<const Rect*>(&s2);
	lws::vector<double> vertex1_[4] = {
		lws::vector<double>(rect1->GetLeft(), rect1->GetTop()),
		lws::vector<double>(rect1->GetLeft(), rect1->GetBottom()),
		lws::vector<double>(rect1->GetRight(), rect1->GetBottom()),
		lws::vector<double>(rect1->GetRight(), rect1->GetTop())
	};

	lws::vector<double> vertex2_[4] = {
		lws::vector<double>(rect2->GetLeft(), rect2->GetTop()),
		lws::vector<double>(rect2->GetLeft(), rect2->GetBottom()),
		lws::vector<double>(rect2->GetRight(), rect2->GetBottom()),
		lws::vector<double>(rect2->GetRight(), rect2->GetTop())
	};

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (CheckLineCrossing(vertex1_[i], vertex1_[(i+1)%4], vertex2_[j], vertex2_[(j != 3) ? j + 1 : 0]))
			{
				return true;
			}

		}
	}
	return false;
}
bool RectRectCollision::CheckLineCrossing(const lws::vector<double> &p1, const lws::vector<double> &p2, const lws::vector<double> &q1, const lws::vector<double> &q2)const{
	//x_座標によるチェック
	if (p1.x_ >= p2.x_){
		if ((p1.x_ < q1.x_ && p1.x_ < q2.x_) || (p2.x_ > q1.x_ || p2.x_ > q2.x_)){
			return false;
		}
	}
	else{
		if ((p2.x_ < q1.x_ && p2.x_ < q2.x_) || (p1.x_ > q1.x_ && p1.x_ > q2.x_)){
			return false;
		}
	}
	//y_座標によるチェック
	if (p1.y_ >= p2.y_){
		if ((p1.y_ < q1.y_ && p1.y_ < q2.y_) || (p2.y_ > q1.y_ && p2.y_ > q2.y_)){
			return false;
		}
	}
	else
	{
		if ((p2.y_ < q1.y_ && p2.y_ < q2.y_) || (p1.y_ > q1.y_ && p1.y_ > q2.y_)){
			return false;
		}
	}

	double tq1 = (p1.x_ - p2.x_)*(q1.y_ - p1.y_) + (p1.y_ - p2.y_)*(p1.x_ - q1.x_);
	double tq2 = (p1.x_ - p2.x_)*(q2.y_ - p1.y_) + (p1.y_ - p2.y_)*(p1.x_ - q2.x_);

	double tp1 = (q1.x_ - q2.x_)*(p1.y_ - q1.y_) + (q1.y_ - q2.y_)*(q1.x_ - p1.x_);
	double tp2 = (q1.x_ - q2.x_)*(p2.y_ - q1.y_) + (q1.y_ - q2.y_)*(q1.x_ - p2.x_);

	return (tq1*tq2 <= 0 && tp1*tp2 <= 0);
}

