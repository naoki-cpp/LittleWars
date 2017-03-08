#pragma once
class SoundControl
{
public:
	SoundControl(char* File, int VolumePal);
	virtual ~SoundControl();
	virtual void Play();
private:
	int sound_handle_;
};

