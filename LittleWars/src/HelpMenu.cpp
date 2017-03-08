#include "..\include\HelpMenu.h"
#include "DxLib.h"

MENU_BEGIN
HelpMenu::HelpMenu(int *Key, MenuStatus &status) :
	MenuPage(2, status, Key),
	kJPNFontHandle(CreateFontToHandle("ＭＳ 明朝", 15, -1))
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


HelpMenu::~HelpMenu()
{
	DeleteFontToHandle(kJPNFontHandle);
}




void HelpMenu::Draw()const {
	DrawStringToHandle(kChoicesDefault.x_, kChoicesDefault.y_ + kMenuSpacing + kChoicesDefault.font_size_, "十字キー::移動 Shift::低速移動", kWhiteColor, kJPNFontHandle);
	DrawStringToHandle(kChoicesDefault.x_, kChoicesDefault.y_ + (kMenuSpacing + kChoicesDefault.font_size_) * 2, "z::ミサイル x_::マシンガン", kWhiteColor, kJPNFontHandle);
	MenuPage::Draw();
}

MENU_END