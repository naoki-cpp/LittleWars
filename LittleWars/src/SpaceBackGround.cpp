#include "..\include\SpaceBackGround.h"
#include "DxLib/DxLib.h"

SpaceBackGround::SpaceBackGround(const lws::Vector<int> & window) :
BackGroundGraphic(window),
kStarSpeed(5),
kElementNum(window.x_ / 150 * window.y_ / 150),
rapid_star_(new lws::Vector<int>[window.x_ / 150 * window.y_ / 150]),
normal_star_(new lws::Vector<int>[window.x_ / 150 * window.y_ / 150]),
slow_star_(new lws::Vector<int>[window.x_ / 150 * window.y_ / 150])
{
	for (size_t i = 0; i < kElementNum; i++)
	{
		rapid_star_[i] = lws::Vector<int>(GetRand(window_.x_), GetRand(window_.y_));
		normal_star_[i] = lws::Vector<int>(GetRand(window_.x_), GetRand(window_.y_));
		slow_star_[i] = lws::Vector<int>(GetRand(window_.x_), GetRand(window_.y_));
	}
}

SpaceBackGround::~SpaceBackGround(){
}

void SpaceBackGround::Update() {
	for (size_t i = 0; i < kElementNum; i++)
	{
		rapid_star_[i] += lws::Vector<int>(0, kStarSpeed * 2);
		if (rapid_star_[i].y_ > int(window_.y_))rapid_star_[i].y_ -= window_.y_;
		normal_star_[i] += lws::Vector<int>(0, kStarSpeed);
		if (normal_star_[i].y_ > int(window_.y_))normal_star_[i].y_ -= window_.y_;
		slow_star_[i] += lws::Vector<int>(0, kStarSpeed / 2);
		if (slow_star_[i].y_ > int(window_.y_))slow_star_[i].y_ -= window_.y_;
	}
}

void SpaceBackGround::Draw()const{
	for (size_t i = 0; i < kElementNum; i++)
	{
		DrawPixel(rapid_star_[i].x_, rapid_star_[i].y_, GetColor(255, 255, 255));

		DrawPixel(normal_star_[i].x_, normal_star_[i].y_, GetColor(255, 255, 255));

		DrawPixel(slow_star_[i].x_, slow_star_[i].y_, GetColor(255, 255, 255));
	}
}
