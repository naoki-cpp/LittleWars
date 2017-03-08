#pragma once
#include "MenuPage.h"

MENU_BEGIN
class HelpMenu :
	public MenuPage
{
public:
	HelpMenu(int *Key, MenuStatus &status);
	virtual ~HelpMenu();
	void Draw()const override;
private:
	const int kJPNFontHandle;
};


MENU_END
