#include <string>
#include "DxLib.h"
#include "..\include\GameOver.h"
#include "..\include\FadeOutNoise.h"

GameOver::GameOver(const int &score, const lws::vector<int> &window, const int screen_handle) :
	waiter_(200),
	score_(score),
	kFontHandle(CreateFontToHandle("‚l‚r –¾’©", 30, -1))
{
}


GameOver::~GameOver()
{
	DeleteFontToHandle(kFontHandle);
}

void GameOver::Initialize(){

}

void GameOver::Update()
{
	waiter_--;
}

void GameOver::Draw() const
{
	DrawFormatStringToHandle(0, 0, GetColor(250, 250, 250), kFontHandle, "GameOver");
	DrawFormatStringToHandle(30, 60, GetColor(250, 250, 250), kFontHandle, "Score::%d", score_);
}

void GameOver::Finalize()
{
	std::ifstream input_file("save.dat");
	int score;
	input_file >> score;
	if (score < score_) {
		std::ofstream output_file("save.dat");
		output_file << std::string(std::to_string(score_));
	}
}

bool GameOver::Finished()
{
	return (waiter_ == 0);
}
