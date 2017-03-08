#pragma once
#include "lws.h"
#include "CreateRainbowColor.h"
#include "MenuPage.h"
#include "BaseScene.h"
#include <memory>

class Menu :
	public BaseScene
{
public:
	Menu(const lws::vector<int>& window, const int screen_handle, int* key, std::shared_ptr<ISceneChanger> changer);
	virtual ~Menu();
	void Initialize()override;
	void Finalize()override;
	void Update()override;
	void Draw()const override;
private:
	int* key_;
	const lws::vector<int> & kWindow;
	const int kScrHandle;
	const menu::MenuPage::MenuElement_t kTitleDefault;
	std::unique_ptr<CreateRainbowColor> rainbow_;
	std::unique_ptr<Task> noise_;
	std::unique_ptr<std::shared_ptr<menu::MenuPage>[]> menu_pages_;
	menu::MenuStatus status_;
	int bgm_handle_;
};

