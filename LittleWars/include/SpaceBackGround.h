#pragma once
#include "BackGroundGraphic.h"
#include <memory>
class SpaceBackGround :
	public BackGroundGraphic
{
public:
	SpaceBackGround(const lws::vector<int> & window);
	virtual ~SpaceBackGround();
	void Draw()const override;
	void Update()override;
private:
	std::unique_ptr<lws::vector<int>[]> rapid_star_;
	std::unique_ptr<lws::vector<int>[]> normal_star_;
	std::unique_ptr<lws::vector<int>[]> slow_star_;
	const int kStarSpeed;
	const size_t kElementNum;
};