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

//�L�[���̎擾
int gpUpdateKey(int Key[256]);

//main�֐�
int WINAPI WinMain(_In_  HINSTANCE hInstance, _In_opt_ HINSTANCE hit_point_revInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	///////////////////////////////////////////////////////////////
	//DxLib�̏�����

	lws::vector<int> window(600, 700); SetWindowText("LittleWars"); SetWindowIconID(ID_ICON);
	ChangeWindowMode(TRUE);
	SetGraphMode(window.x_, window.y_, 32);
	if (DxLib_Init() == -1)return -1;
	//SetDXArchiveExtension("dat");
	int screen_handle = MakeScreen(window.x_, window.y_);
	SetDrawScreen(screen_handle); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	//�����������܂�
	//////////////////////////////////////////////////////////////////////
	//�I�u�W�F�N�g������
	FpsAdjuster fps;//fps����
	int key[256];  //�L�[��������Ă���t���[�������i�[����
	std::shared_ptr<SceneManager> ScMgr(std::make_shared<SceneManager>(window, screen_handle, key));
	ScMgr->Initialize();
	//�I�u�W�F�N�g�����������܂�
	////////////////////////////////////////////////////////
	//���C�����[�v
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey(key) == 0) {
		//��ʏ�����
		SetDrawScreen(screen_handle);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		ClearDrawScreen();
		//���C������
		ScMgr->Update();
		if (ScMgr->End())break;
		ScMgr->Draw();
		fps.Update();	//�X�V
		fps.Draw();		//�`��
		//��ʂɔ��f
		SetDrawScreen(DX_SCREEN_BACK);
		DrawGraph(0, 0, screen_handle, FALSE);
		//fps����
		fps.Wait();		//�ҋ@
	}
	//���C�����[�v�����܂�
	/////////////////////////////////////////////////////////////////
	DxLib_End(); // DX���C�u�����I������
	return 0;
}


int gpUpdateKey(int Key[256]) {
	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			Key[i]++;     // ���Z
		}
		else {              // ������Ă��Ȃ����
			Key[i] = 0;   // 0�ɂ���
		}
	}
	return 0;
}