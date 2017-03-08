#pragma once
#include "SoundControl.h"
#include "Resource.h"
class ExplosionSound :
	public SoundControl
{
public:

	ExplosionSound() :
		SoundControl(EXPLOSION_SOUND_EFFECT,125)
	{
	}

	virtual ~ExplosionSound()
	{
	}
};

