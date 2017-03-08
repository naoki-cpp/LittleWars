#include "../include/ExplosionEffect.h"
#include "../include/ExplosionSound.h"

ExplosionEffect::ExplosionEffect(std::shared_ptr<GraphicElement> graphic, const lws::vector<int> &coordinate, const double angle) :
	Effect(graphic, coordinate, angle),
	effect_interval_(3),
	effect_timer_(0)
{
	explosion_sound_ = std::unique_ptr<SoundControl>(std::make_unique<ExplosionSound>());
}

ExplosionEffect::~ExplosionEffect()
{
	explosion_sound_.reset();
}

void ExplosionEffect::Initialize()
{
	explosion_sound_->Play();
}

void ExplosionEffect::Update()
{
	++effect_timer_;
	if (effect_timer_ % effect_interval_ == 0)
	{
		InclimentCounter();
	}
}

void ExplosionEffect::Draw() {
	Effect::Draw();
}