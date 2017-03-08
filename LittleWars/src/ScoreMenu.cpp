#include "..\include\ScoreMenu.h"
#include "DxLib.h"

MENU_BEGIN
const size_t ScoreMenu::kBuffferSize = 256;
ScoreMenu::ScoreMenu(int* Key, MenuStatus &status) :
	MenuPage(1, status, Key),
	kJPNFontHandle(CreateFontToHandle("‚l‚r –¾’©", 15, -1)),
	input_file_("save.dat")
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


ScoreMenu::~ScoreMenu()
{
}
void ScoreMenu::Initialize()
{
	input_file_ >> score_;
}
void ScoreMenu::Finalize()
{
	DeleteFontToHandle(kJPNFontHandle);
}
void ScoreMenu::Update() {
	MenuPage::Update();
}
void ScoreMenu::Draw()const {
	DrawFormatStringToHandle(kChoicesDefault.x_, kChoicesDefault.y_ + kMenuSpacing + kChoicesDefault.font_size_, kWhiteColor, kJPNFontHandle,"The Best Score is...%s", score_.c_str());
	MenuPage::Draw();
}

MENU_END