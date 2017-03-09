#pragma once
#include <memory>
#include <fstream>
#include <string>
#include "Task.h"
#include "Noise.h"
class GameOver :
	public Task
{
public:
	GameOver(const int &score, const lws::Vector<int> &window, const int screen_handle);
	virtual ~GameOver();
	void Initialize()override;
	void Update()override;
	void Draw()const override;
	void Finalize()override;
	bool Finished();
private:
	size_t waiter_;
	std::unique_ptr<Noise> noise_;
	const int &score_;
	const int kFontHandle;
};

