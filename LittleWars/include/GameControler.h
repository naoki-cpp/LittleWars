#pragma once
#include "GameObject.h"
#include <memory>
class GameControler
{
public:

	virtual ~GameControler()
	{
	}

	//オブジェクト加える
	virtual void AddObject(std::shared_ptr<GameObject>) = 0;

	//スコアを加える
	virtual void AddScore(int score) {
		score_ += score;
	}

	//クリアしたことを伝える
	virtual void InformOfBeingCleared() = 0;
protected:
	GameControler():
		score_(0) {}
	int score_;
private:
	GameControler(GameControler&);
};