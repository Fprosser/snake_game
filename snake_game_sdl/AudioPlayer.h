#pragma once
#include "SDL.h"

class AudioPlayer
{
public:
	AudioPlayer();
private:
	SDL_AudioSpec wav_spec;
	Uint32 wav_length;
	Uint8* wav_buffer;

	SDL_AudioSpec desired;
	SDL_AudioSpec obtained;
};

