#pragma once
#include "GameObject.h"
#include <memory>
class GameControler
{
public:

	virtual ~GameControler()
	{
	}

	//�I�u�W�F�N�g������
	virtual void AddObject(std::shared_ptr<GameObject>) = 0;

	//�X�R�A��������
	virtual void AddScore(int score) {
		score_ += score;
	}

	//�N���A�������Ƃ�`����
	virtual void InformOfBeingCleared() = 0;
protected:
	GameControler():
		score_(0) {}
	int score_;
private:
	GameControler(GameControler&);
};