#pragma once
class CreateRainbowColor
{
public:
	CreateRainbowColor();
	virtual ~CreateRainbowColor();
	unsigned int GetRainbow();
private:
	template<class T>T square(T x_) { return x_*x_; }

	int rainbow_count_;
};