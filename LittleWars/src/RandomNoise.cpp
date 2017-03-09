#include "DxLib/DxLib.h"
#include "..\include\RandomNoise.h"


RandomNoise::RandomNoise(const lws::Vector<int> &window, const int screen_handle, uint32_t NoiseNum):
	Noise(window,screen_handle,NoiseNum)
{
}


RandomNoise::~RandomNoise()
{
}

void RandomNoise::Update()
{
	if (GetRand(1000) % 1000 == 0)
	{
		noise_count_ = GetRand(40) + 20;
		NoiseReset();
	}
	if (noise_count_ > 0)
	{
		if (CheckSoundMem(noise_sound_handle_) == 0)PlaySoundMem(noise_sound_handle_, DX_PLAYTYPE_BACK);

		for (size_t i = 0; i < kNoiseNum; i++)
		{
			//ƒmƒCƒY‚ð‚ä‚ç‚ä‚ç‚³‚¹‚é
			int RandomSpeed = (((GetRand(8) % 4) > 2) * 2 - 1) * 2;
			box_[i].vertex1_.x_ += RandomSpeed;
			box_[i].vertex2_.x_ += RandomSpeed;
		}
		if (noise_count_-- % 6 == 1)
		{
			NoiseReset();
		}
	}
	else
	{
		StopSoundMem(noise_sound_handle_);
	}
}

void RandomNoise::Draw() const
{
	if (noise_count_ > 0)
	{
		Noise::Draw();
	}
}
