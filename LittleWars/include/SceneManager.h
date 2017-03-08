#pragma once
#include "ISceneChanger.h"
#include "Task.h"
#include "BaseScene.h"
#include "lws.h"
#include "memory"

class SceneManager :
	public ISceneChanger,public Task,public std::enable_shared_from_this<ISceneChanger>
{
public:
	SceneManager(const lws::vector<int>& window, const int screen_handle, int* key);
	virtual ~SceneManager();
	void Initialize() override;//初期化
	void Finalize() override;//終了処理
	void Update() override;//更新
	void Draw()const override;//描画
	bool End();
    // 引数 nextScene にシーンを変更する
    void ChangeScene(eScene NextScene) override;
private:
	std::shared_ptr<BaseScene> scene_;
	eScene next_scene_;
	int* key_;
	const lws::vector<int>& window_;
	int screen_handle_;
	bool end_flag_;
};

