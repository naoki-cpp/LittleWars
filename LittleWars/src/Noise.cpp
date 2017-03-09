#include <cmath>
#include "DxLib/DxLib.h"
#include "..\include\Noise.h"
#include "../include/Resource.h"

Noise::Noise(const lws::Vector<int> &window, const int screen_handle, uint32_t noise_num) :
	kWindow(window),
	kScrHandle(screen_handle),
	kNoiseNum(noise_num),
	kReductionRatio(4),
	box_(new BoxElement[noise_num]()),
	noise_sound_handle_(LoadSoundMem(NOISE_SOUND_EFFECT))
{
}


Noise::~Noise()
{
}

void Noise::Initialize()
{
	NoiseReset();
}

void Noise::Finalize()
{
	DeleteSoundMem(noise_sound_handle_);
}

void Noise::Draw() const
{
	for (size_t i = 0; i < kNoiseNum; i++)
	{
		NoiseCreate(i);

	}
}

void Noise::NoiseReset() {
	for (size_t i = 0; i < kNoiseNum; i++)
	{
		lws::Vector<int> vertex(GetRand(kWindow.x_), GetRand(kWindow.y_));
		box_[i] = BoxElement(lws::Vector<int>(vertex.x_, vertex.y_), lws::Vector<int>(vertex.x_ + GetRand(kWindow.x_ - vertex.x_), vertex.y_ + GetRand(kWindow.y_ - vertex.y_)));
	}
}

void Noise::NoiseCreate(size_t i)const
{
	if (i <= kNoiseNum)
	{
		//ˆê“xk¬‚µ‚Ä‚©‚çŠg‘å•`‰æ‚·‚é‚±‚Æ‚Å‰æ‘œ‚ð˜c‚Ü‚¹‚é
		int graph_handle = MakeScreen(static_cast<int>((box_[i].vertex2_.x_ - box_[i].vertex1_.x_) / kReductionRatio), static_cast<int>((box_[i].vertex2_.y_ - box_[i].vertex1_.y_) / kReductionRatio));
		if (graph_handle != -1)
		{
			GraphFilterRectBlt(kScrHandle, graph_handle, box_[i].vertex1_.x_, box_[i].vertex1_.y_, box_[i].vertex2_.x_, box_[i].vertex2_.y_, 0, 0, DX_GRAPH_FILTER_DOWN_SCALE, kReductionRatio);
			DrawExtendGraph(box_[i].vertex1_.x_, box_[i].vertex1_.y_, box_[i].vertex2_.x_, box_[i].vertex2_.y_, graph_handle, FALSE);
			DeleteGraph(graph_handle);
		}
	}
}
