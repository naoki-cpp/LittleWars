#pragma once
#include <memory>
#include "Effect.h"
#include "SoundControl.h"
#include "NullShape.h"
class ExplosionEffect :
	public Effect, NullShape
{
public:

	explicit ExplosionEffect(std::shared_ptr<GraphicElement> graphic, const lws::Vector<int> &coordinate, const double angle);
	virtual ~ExplosionEffect();
	void Initialize()override;
	void Update()override;
	void Draw();
private:
	std::unique_ptr<SoundControl> explosion_sound_;
	//�G�t�F�N�g�̕\���Ԋu
	size_t effect_interval_;
	size_t effect_timer_;
};