#include "..\include\MainMenu.h"
#include "../include/HelpMenu.h"
#include "../include/ScoreMenu.h"
#include "../include/ConfigureMenu.h"

MENU_BEGIN
MainMenu::MainMenu(int *Key, MenuStatus &status) :
MenuPage(5,status,Key)
{
	std::string a_MenuArticle[] = {
		"./start",
		"./help",
		"./score",
		"./configure",
		"./end"
	};
	MenuStatus a_MenuStatus[] = {
		MenuStatus::START,
		MenuStatus::HELP,
		MenuStatus::SCORE,
		MenuStatus::CONFIGURE,
		MenuStatus::END
	};
	for (size_t i = 0; i < kElementNum; i++)
	{
		menu_element_[i].x_ = kChoicesDefault.x_;
		menu_element_[i].y_ = i * (kChoicesDefault.font_size_ + kMenuSpacing) + kChoicesDefault.y_;
		menu_element_[i].article_ = a_MenuArticle[i];
		menu_element_[i].font_handle_ = kChoicesDefault.font_handle_;
		menu_element_[i].font_size_ = kChoicesDefault.font_size_;
		menu_element_[i].status_ = a_MenuStatus[i];
	}
}


MainMenu::~MainMenu()
{
}

void MainMenu::Update(){
	MenuPage::Update();
}

MENU_END