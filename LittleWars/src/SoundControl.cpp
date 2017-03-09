#include "..\include\SoundControl.h"
#include "DxLib/DxLib.h"

SoundControl::SoundControl(char* File,int VolumePal)

{
	sound_handle_ = (LoadSoundMem(File));
	ChangeVolumeSoundMem(VolumePal,sound_handle_);
}
void SoundControl::Play(){
	PlaySoundMem(sound_handle_, DX_PLAYTYPE_BACK, true);

}

SoundControl::~SoundControl()
{
	DeleteSoundMem(sound_handle_);
}
