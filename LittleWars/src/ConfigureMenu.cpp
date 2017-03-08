#include "..\include\ConfigureMenu.h"
#include "DxLib.h"

MENU_BEGIN
ConfigureMenu::ConfigureMenu(int* Key, MenuStatus &status) :
	MenuPage(1, status, Key),
	kJPNFontHandle(CreateFontToHandle("‚l‚r –¾’©", 15, -1))
{
	for (size_t i = 0; i < kElementNum; i++)
	{
		menu_element_[i].x_ = kChoicesDefault.x_;
		menu_element_[i].y_ = kChoicesDefault.y_;
		menu_element_[i].article_ = "Return to Main Menu";
		menu_element_[i].font_handle_ = kChoicesDefault.font_handle_;
		menu_element_[i].font_size_ = kChoicesDefault.font_size_;
		menu_element_[i].status_ = MenuStatus::CHOOSING;
	}
}


ConfigureMenu::~ConfigureMenu()
{
}

void ConfigureMenu::Update() {
	MenuPage::Update();
}

void ConfigureMenu::Draw()const {
	DrawStringToHandle(kChoicesDefault.x_, kChoicesDefault.y_ + kMenuSpacing + kChoicesDefault.font_size_, "HŽ–’†", kWhiteColor, kJPNFontHandle);
	MenuPage::Draw();
}
MENU_END