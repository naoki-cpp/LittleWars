#pragma once
#include "MenuPage.h"
#include "ISceneChanger.h"

MENU_BEGIN
class StartMenu :
	public MenuPage
{
public:
	StartMenu(int* Key, MenuStatus &status,std::shared_ptr<ISceneChanger> changer);
	virtual ~StartMenu();
	void Update()override;
private:
	std::shared_ptr<ISceneChanger> changer_;
};


MENU_END
