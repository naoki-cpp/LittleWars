#include "..\include\FadeOutNoise.h"



FadeOutNoise::FadeOutNoise(const lws::Vector<int> &window, const int screen_handle, uint32_t noise_num):
	Noise(window,screen_handle,noise_num),
	fade_out_counter_(noise_num),
	kFadeOutInterval(1)
{
}


FadeOutNoise::~FadeOutNoise()
{
}

void FadeOutNoise::Initialize()
{
	NoiseReset();
}

void FadeOutNoise::Update()
{
	fade_out_counter_ -= ((fade_out_counter_  > 0) && ((++timer_) % kFadeOutInterval == 0));
}

void FadeOutNoise::Draw() const
{
	for (size_t i = 0; i < fade_out_counter_; i++)
	{
		NoiseCreate(i);
	}
}
