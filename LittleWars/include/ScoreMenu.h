#pragma once
#include <fstream>
#include <string>
#include "MenuPage.h"

MENU_BEGIN

class ScoreMenu :
	public MenuPage
{
public:
	ScoreMenu(int* Key, MenuStatus &status);
	virtual ~ScoreMenu();
	void Initialize()override;
	void Finalize()override;
	void Update() override;
	void Draw()const override;
private:
	const int kJPNFontHandle;
	const static size_t kBuffferSize;
	std::ifstream input_file_;
	std::string score_;
};
MENU_END