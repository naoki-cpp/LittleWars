#include "..\include\CreateRainbowColor.h"
#include "DxLib/DxLib.h"
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>

CreateRainbowColor::CreateRainbowColor()
{
}


CreateRainbowColor::~CreateRainbowColor()
{
}

unsigned int CreateRainbowColor::GetRainbow(){
	rainbow_count_++;
	return GetColor(static_cast<int>(square(sin(rainbow_count_ / 1000.0  * M_PI / 3.0))*255.0),
		static_cast<int>(square(sin(rainbow_count_ / 1000.0 * M_PI * 2.0 / 3.0)) * 255.0),
		static_cast<int>(square(sin(rainbow_count_ / 1000.0 * M_PI)) * 255.0));
}