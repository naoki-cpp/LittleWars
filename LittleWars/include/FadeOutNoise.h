#pragma once
#include "Noise.h"
class FadeOutNoise :
	public Noise
{
public:
	FadeOutNoise(const lws::Vector<int> &window, const int screen_handle, uint32_t NoiseNum);
	~FadeOutNoise();
	void Initialize()override;
	void Update()override;
	void Draw()const override;
private:
	uint32_t fade_out_counter_;
	uint32_t timer_;
	const uint32_t kFadeOutInterval;
};

