#include "DxLib.h"
#include "..\include\Menu.h"
#include "../include/MainMenu.h"
#include "../include/StartMenu.h"
#include "../include/HelpMenu.h"
#include "../include/ScoreMenu.h"
#include "../include/ConfigureMenu.h"
#include "../include/EndMenu.h"
#include "../include\RandomNoise.h"
#include "../include/Resource.h"
Menu::Menu(const lws::vector<int>& window, const int screen_handle, int* key, std::shared_ptr<ISceneChanger> changer) :
	BaseScene(changer, screen_handle),
	kWindow(window),
	kScrHandle(screen_handle),
	kTitleDefault(0, 0, "LonelyBattle", CreateFontToHandle("‚l‚r –¾’©", 30, -1), 30),
	key_(key),
	rainbow_(std::make_unique<CreateRainbowColor>()),
	noise_(std::make_unique<RandomNoise>(window, screen_handle, 10)),
	status_(menu::MenuStatus::CHOOSING),
	menu_pages_(new std::shared_ptr<menu::MenuPage>[menu::MENU_NUM]),
	bgm_handle_(0)
{
	menu_pages_[menu::CHOOSING] = std::make_shared<menu::MainMenu>(key, status_);
	menu_pages_[menu::START] = std::make_shared<menu::StartMenu>(key, status_, changer);
	menu_pages_[menu::HELP] = std::make_shared<menu::HelpMenu>(key, status_);
	menu_pages_[menu::SCORE] = std::make_shared<menu::ScoreMenu>(key, status_);
	menu_pages_[menu::CONFIGURE] = std::make_shared<menu::ConfigureMenu>(key, status_);
	menu_pages_[menu::END] = std::make_shared<menu::EndMenu>(key, status_, changer);
}

Menu::~Menu()
{
	DeleteFontToHandle(kTitleDefault.font_handle_);
}
void Menu::Initialize() {
	for (size_t i = 0; i < menu::MENU_NUM; i++)
	{
		menu_pages_[i]->Initialize();
	}
	bgm_handle_ = LoadSoundMem(MENU_BGM);
	PlaySoundMem(bgm_handle_, DX_PLAYTYPE_LOOP);
	noise_->Initialize();
}

void Menu::Finalize()
{
	for (size_t i = 0; i < menu::MENU_NUM; i++)
	{
		menu_pages_[i]->Finalize();
	}
	noise_->Finalize();
	StopSoundMem(bgm_handle_);
	DeleteSoundMem(bgm_handle_);
}

void Menu::Update() {
	menu_pages_[status_]->Update();
	noise_->Update();
}

void Menu::Draw()const {
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawStringToHandle(kTitleDefault.x_, kTitleDefault.y_, kTitleDefault.article_.c_str(), rainbow_->GetRainbow(), kTitleDefault.font_handle_);
	menu_pages_[status_]->Draw();
	DrawString(0, 200, "Protect your territory alone...", GetColor(200, 200, 200));
	noise_->Draw();
}