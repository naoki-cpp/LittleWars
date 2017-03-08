#include "..\include\SpaceBackGround.h"
#include "DxLib.h"

SpaceBackGround::SpaceBackGround(const lws::vector<int> & window) :
BackGroundGraphic(window),
kStarSpeed(5),
kElementNum(window.x_ / 150 * window.y_ / 150),
rapid_star_(new lws::vector<int>[window.x_ / 150 * window.y_ / 150]),
normal_star_(new lws::vector<int>[window.x_ / 150 * window.y_ / 150]),
slow_star_(new lws::vector<int>[window.x_ / 150 * window.y_ / 150])
{
	for (size_t i = 0; i < kElementNum; i++)
	{
		rapid_star_[i] = lws::vector<int>(GetRand(window_.x_), GetRand(window_.y_));
		normal_star_[i] = lws::vector<int>(GetRand(window_.x_), GetRand(window_.y_));
		slow_star_[i] = lws::vector<int>(GetRand(window_.x_), GetRand(window_.y_));
	}
}

SpaceBackGround::~SpaceBackGround(){
}

void SpaceBackGround::Update() {
	for (size_t i = 0; i < kElementNum; i++)
	{
		rapid_star_[i] += lws::vector<int>(0, kStarSpeed * 2);
		if (rapid_star_[i].y_ > int(window_.y_))rapid_star_[i].y_ -= window_.y_;
		normal_star_[i] += lws::vector<int>(0, kStarSpeed);
		if (normal_star_[i].y_ > int(window_.y_))normal_star_[i].y_ -= window_.y_;
		slow_star_[i] += lws::vector<int>(0, kStarSpeed / 2);
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
