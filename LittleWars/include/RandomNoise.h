#pragma once
#include "Noise.h"
class RandomNoise :
	public Noise
{
public:
	RandomNoise(const lws::Vector<int> &window, const int screen_handle, uint32_t NoiseNum);
	~RandomNoise();
	void Update()override;
	void Draw()const override;
private:
	int noise_count_;
};

