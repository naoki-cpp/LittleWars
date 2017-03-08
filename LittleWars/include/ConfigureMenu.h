#pragma once
#include "MenuPage.h"
MENU_BEGIN
class ConfigureMenu :
	public MenuPage
{
public:
	ConfigureMenu(int* Key, MenuStatus &status);
	virtual ~ConfigureMenu();
	void Update()override;
	void Draw()const override;
private:
	const uint32_t kJPNFontHandle;
};
MENU_END
