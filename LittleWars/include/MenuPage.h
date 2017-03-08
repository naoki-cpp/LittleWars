#pragma once
#include <memory>
#include <string>
#include "Task.h"
#define MENU_BEGIN namespace menu{
#define MENU_END }

MENU_BEGIN
enum MenuStatus:size_t
{
	CHOOSING,
	START,
	HELP,
	SCORE,
	CONFIGURE,
	END,
	MENU_NUM
};
class MenuPage :public Task
{
public:
	virtual ~MenuPage();
	void Update()override;
	void Draw()const override;
	struct MenuElement_t {
		MenuElement_t() {}
		MenuElement_t(int x_, int y_,const std::string article_, int font_handle_, uint32_t font_size_) :
			x_(x_), y_(y_), article_(article_), font_handle_(font_handle_), font_size_(font_size_) {}
		int x_;
		int y_;
		std::string article_;
		int font_handle_;
		unsigned int font_size_;
		MenuStatus status_;
	};
protected:
	MenuPage(const size_t kElementNum, MenuStatus &status, int *key);
	const MenuElement_t kChoicesDefault;
	const int kMenuSpacing; //çsä‘ÇÃïù
	const size_t kElementNum;
	const unsigned int kWhiteColor;
	const unsigned int kBlueColor;
	const unsigned int kGlayColor;
	const uint32_t kCursorWaitTime;
	size_t cursor_timer_;
	std::unique_ptr<MenuElement_t[]> menu_element_;
	MenuStatus &status_;
	int *key_;
	bool changing_scene_;
	void DrawCursor()const;
private:
	int cursor_;
};
MENU_END

