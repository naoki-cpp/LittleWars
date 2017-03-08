#pragma once
#include "Task.h"
#include "ISceneChanger.h"
#include <memory>
class BaseScene :
	public Task
{
public:
	BaseScene(std::shared_ptr<ISceneChanger> changer, int screen_handle) :
		changer_(changer),
		screen_handle_(screen_handle)
	{
	}
	virtual ~BaseScene(){};
protected:
	int screen_handle_;
	std::shared_ptr<ISceneChanger> changer_;
private:
};

