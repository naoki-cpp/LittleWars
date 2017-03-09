#include "..\include\MenuPage.h"
#include "DxLib/DxLib.h"
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>

MENU_BEGIN

MenuPage::MenuPage(const size_t kElementNum, MenuStatus & status, int * key) :
	menu_element_(new MenuElement_t[kElementNum]),
	kChoicesDefault(50, 60, "", CreateFontToHandle("Century", 15, -1), 10),
	kMenuSpacing(5),
	kElementNum(kElementNum),
	kWhiteColor(GetColor(255, 255, 255)),
	kBlueColor(GetColor(0, 150, 255)),
	kGlayColor(GetColor(100,100,100)),
	kCursorWaitTime(30),
	key_(key),
	cursor_(0),
	status_(status),
	cursor_timer_(0),
	changing_scene_(false)
{
}


MenuPage::~MenuPage()
{
	DeleteFontToHandle(kChoicesDefault.font_handle_);
}

void MenuPage::Update() {
	cursor_ = (cursor_ +
		static_cast<int>(key_[KEY_INPUT_DOWN] == 1) - static_cast<int>(key_[KEY_INPUT_UP] == 1)
		+ kElementNum) % kElementNum;
	if (key_[KEY_INPUT_RETURN] > 0 || key_[KEY_INPUT_Z] > 0)
	{
		changing_scene_ = true;
	}
	else
	{
	}
	if (changing_scene_)++cursor_timer_;
	if (cursor_timer_ > kCursorWaitTime)
	{
		status_ = menu_element_[cursor_].status_;
		cursor_timer_ = 0;
		changing_scene_ = false;
	}
}

void MenuPage::Draw()const {
	for (size_t i = 0; i < kElementNum; i++)
	{
		DrawStringToHandle(menu_element_[i].x_, menu_element_[i].y_, menu_element_[i].article_.c_str(), kWhiteColor, menu_element_[i].font_handle_);
	}
	DrawCursor();
}
void MenuPage::DrawCursor()const {
	int cursor_x = menu_element_[cursor_].x_ - menu_element_[cursor_].font_size_ * 3;
	int cursor_y = menu_element_[cursor_].y_ + menu_element_[cursor_].font_size_ / 2;
	int radius = menu_element_[cursor_].font_size_;
	for (size_t i = 0; i < static_cast<size_t>(cursor_timer_ * 6 / (kCursorWaitTime / 1.2)); i++)
	{
		DrawTriangle(cursor_x, cursor_y,
			static_cast<int>(cursor_x + radius*cos(static_cast<int>(1 - i)*M_PI / 3)), static_cast<int>(cursor_y - radius*sin(static_cast<int>(1 - i)*M_PI / 3)),
			static_cast<int>(cursor_x + radius*cos(-static_cast<int>(i)*M_PI / 3)), static_cast<int>(cursor_y - radius*sin(-static_cast<int>(i)*M_PI / 3)), kBlueColor, TRUE);

	}
	for (size_t i = 0; i < 6; i++)
	{
		DrawTriangle(cursor_x, cursor_y,
			static_cast<int>(cursor_x + radius*cos(static_cast<int>(1 - i)*M_PI / 3)), static_cast<int>(cursor_y - radius*sin(static_cast<int>(1 - i)*M_PI / 3)),
			static_cast<int>(cursor_x + radius*cos(-static_cast<int>(i)*M_PI / 3)), static_cast<int>(cursor_y - radius*sin(-static_cast<int>(i)*M_PI / 3)), kGlayColor, FALSE);

	}
	DrawStringToHandle(cursor_x + menu_element_[cursor_].font_size_, cursor_y - menu_element_[cursor_].font_size_ / 2, "->", kWhiteColor, kChoicesDefault.font_handle_);
}
MENU_END