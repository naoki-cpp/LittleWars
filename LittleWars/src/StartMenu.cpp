#include "..\include\StartMenu.h"

MENU_BEGIN

StartMenu::StartMenu(int* Key, MenuStatus &status,std::shared_ptr<ISceneChanger> changer) :
MenuPage(1,status,Key),
changer_(changer)
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


StartMenu::~StartMenu()
{
}

void StartMenu::Update(){
	if (changer_)changer_->ChangeScene(eScene::GAME); else
	{
		MenuPage::Update();
	}
}
MENU_END
