#pragma once
#include "MenuPage.h"
MENU_BEGIN
class MainMenu :
	public MenuPage
{
public:
	MainMenu(int *Key, MenuStatus &status);
	virtual ~MainMenu();
	void Update()override;
};

MENU_END