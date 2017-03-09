#include "..\include\SceneManager.h"
#include "DxLib/DxLib.h"
#include "../include/Menu.h"
#include "../include/GameManager.h"

SceneManager::SceneManager(const lws::Vector<int>& window, const int screen_handle, int* key) :
	next_scene_(eScene::NONE),
	key_(key),
	window_(window),
	screen_handle_(screen_handle),
	end_flag_(false)
{
}


SceneManager::~SceneManager()
{
}
void SceneManager::Initialize() {
	scene_ = (std::make_shared<Menu>(window_, screen_handle_, key_, shared_from_this()));
	scene_->Initialize();
}
void SceneManager::Finalize() {
	scene_->Finalize();
}
void SceneManager::Update() {
	if (next_scene_ != eScene::END) {
		if (next_scene_ != eScene::NONE)
		{
			scene_->Finalize();//現在のシーンの終了処理を実行
			switch (next_scene_)
			{
			case eScene::MENU:
				scene_.reset(new Menu(window_, screen_handle_, key_, shared_from_this()));
				break;
			case eScene::GAME:
				scene_.reset(new GameManager(key_, window_, shared_from_this(), screen_handle_));
				break;
			case eScene::END:
				end_flag_ = true;
				break;
			default:
				break;
			}
			next_scene_ = eScene::NONE;//次のシーン情報をクリア
			scene_->Initialize(); //シーンを初期化
		}
		scene_->Update();
	}
	else
	{
		end_flag_ = true;
	}
}
void SceneManager::Draw()const {
	scene_->Draw();//シーンの描画
}
bool SceneManager::End()
{
	return end_flag_;
}
void SceneManager::ChangeScene(eScene NextScene) {
	next_scene_ = NextScene;//次のシーンをセットする
}