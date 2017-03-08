#pragma once
#include "MenuPage.h"
#include "ISceneChanger.h"
MENU_BEGIN
class EndMenu :
	public MenuPage
{
public:
	EndMenu(int* Key, MenuStatus &status, std::shared_ptr<ISceneChanger> changer);
	virtual ~EndMenu();
	void Update()override;
private:
	std::shared_ptr<ISceneChanger> changer_;
};
MENU_END

