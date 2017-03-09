#pragma once
#include "BackGroundGraphic.h"
#include <memory>
class SpaceBackGround :
	public BackGroundGraphic
{
public:
	SpaceBackGround(const lws::Vector<int> & window);
	virtual ~SpaceBackGround();
	void Draw()const override;
	void Update()override;
private:
	std::unique_ptr<lws::Vector<int>[]> rapid_star_;
	std::unique_ptr<lws::Vector<int>[]> normal_star_;
	std::unique_ptr<lws::Vector<int>[]> slow_star_;
	const int kStarSpeed;
	const size_t kElementNum;
};