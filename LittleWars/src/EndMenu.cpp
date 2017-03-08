#include "..\include\EndMenu.h"

MENU_BEGIN
EndMenu::EndMenu(int* Key, MenuStatus &status, std::shared_ptr<ISceneChanger> changer) :
	MenuPage(0, status, Key),
	changer_(changer)
{
}


EndMenu::~EndMenu()
{
}

void EndMenu::Update() {
	changer_->ChangeScene(eScene::END);
}


MENU_END
