#include "SoundManager.h"

SoundManager* SoundManager::s_pInstance = NULL;

void SoundManager::play(std::string filename) {
	Mix_Music* music = Mix_LoadMUS(filename.c_str());
	Mix_PlayMusic(music, 0);

}