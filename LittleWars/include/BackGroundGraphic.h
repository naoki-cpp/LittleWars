#pragma once
#include "lws.h"
#include "Task.h"
class BackGroundGraphic :public Task
{
public:
	BackGroundGraphic(const lws::vector<int> & window) :
		window_(window)
	{}
	virtual ~BackGroundGraphic() {};
protected:
	const lws::vector<int> & window_;
};

