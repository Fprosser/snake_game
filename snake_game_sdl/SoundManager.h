#pragma once
#ifndef __SOUNDMANAGER__
#define __SOUNDMANAGER__
#include "SDL.h"
#include "SDL_mixer.h"
#include <string.h>
#include <iostream>
class SoundManager
{
public:

	void play(std::string filename);

	static SoundManager* Instance()
	{
		if (s_pInstance == NULL)
		{
			s_pInstance = new SoundManager();
			SoundManager::initAudioDevice();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
    static void initAudioDevice()
    {
        if (SDL_Init(SDL_INIT_AUDIO) != -1)
        {
            if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
            {
                std::cerr << "\n Error initializing audio device...\n";
            }
            else
            {
                std::cout << "\n successful audio init \n";
            }
        }
        else
        {
            std::cerr << "Error initializing SDL audio subsystem...\n";
        }
    }

	SoundManager() {}
	static SoundManager* s_pInstance;

};

#endif // !__SOUNDMANAGER__

