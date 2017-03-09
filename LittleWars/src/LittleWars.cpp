//-------------------------------------------------------------------------------
//		Copyright 2015 NaokiYano
//
//			LittleWars ver 0.08
//
//
//-------------------------------------------------------------------------------
#include <memory>
#include "DxLib.h"
#include "../include/SceneManager.h"
#include "../include/lws.h"
#include "../include/FpsAdjuster.h"
#include "../include/Resource.h"

//キー情報の取得
int gpUpdateKey(int Key[256]);

//main関数
int WINAPI WinMain(_In_  HINSTANCE hInstance, _In_opt_ HINSTANCE hit_point_revInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	///////////////////////////////////////////////////////////////
	//DxLibの初期化

	lws::vector<int> window(600, 700); SetWindowText("LittleWars"); SetWindowIconID(ID_ICON);
	ChangeWindowMode(TRUE);
	SetGraphMode(window.x_, window.y_, 32);
	if (DxLib_Init() == -1)return -1;
	//SetDXArchiveExtension("dat");
	int screen_handle = MakeScreen(window.x_, window.y_);
	SetDrawScreen(screen_handle); //ウィンドウモード変更と初期化と裏画面設定

	//初期化ここまで
	//////////////////////////////////////////////////////////////////////
	//オブジェクト初期化
	FpsAdjuster fps;//fps制御
	int key[256];  //キーが押されているフレーム数を格納する
	std::shared_ptr<SceneManager> ScMgr(std::make_shared<SceneManager>(window, screen_handle, key));
	ScMgr->Initialize();
	//オブジェクト初期化ここまで
	////////////////////////////////////////////////////////
	//メインループ
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey(key) == 0) {
		//画面初期化
		SetDrawScreen(screen_handle);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		ClearDrawScreen();
		//メイン処理
		ScMgr->Update();
		if (ScMgr->End())break;
		ScMgr->Draw();
		fps.Update();	//更新
		fps.Draw();		//描画
		//画面に反映
		SetDrawScreen(DX_SCREEN_BACK);
		DrawGraph(0, 0, screen_handle, FALSE);
		//fps制御
		fps.Wait();		//待機
	}
	//メインループここまで
	/////////////////////////////////////////////////////////////////
	DxLib_End(); // DXライブラリ終了処理
	return 0;
}


int gpUpdateKey(int Key[256]) {
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			Key[i]++;     // 加算
		}
		else {              // 押されていなければ
			Key[i] = 0;   // 0にする
		}
	}
	return 0;
}