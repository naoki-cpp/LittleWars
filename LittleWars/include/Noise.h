#pragma once
#include "lws.h"
#include <memory>
#include "Task.h"


class Noise :public Task
{
public:
	Noise(const lws::vector<int> &window, const int screen_handle, uint32_t noise_num);
	virtual ~Noise();
	virtual void Initialize()override;
	virtual void Finalize()override;
	virtual void Update()override {};
	virtual void Draw()const override;
protected:
	struct BoxElement {
		BoxElement() {}
		BoxElement(const lws::vector<int>& vertex1, const lws::vector<int>& vertex2) :
			vertex1_(vertex1),
			vertex2_(vertex2)
		{}
		~BoxElement() {}
		lws::vector<int> vertex1_;
		lws::vector<int> vertex2_;
	};
	std::unique_ptr<BoxElement[]> box_;
	const size_t kNoiseNum;
	const lws::vector<int>& kWindow;
	const int kScrHandle;
	const uint32_t kReductionRatio;
	void NoiseReset();
	void NoiseCreate(size_t i)const;
	int noise_sound_handle_;
};

