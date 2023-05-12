#pragma once
#ifndef __Game__
#define __Game__
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"
#include "GameState.h"
#include "GameStateMachine.h"
#include "SoundManager.h"
#include <vector> 


class Game
{
public:

	//Setting the running variable to true
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running();
	void quit();

	int m_currentFrame;


	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;

	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

	std::vector<GameObject*> m_gameObjects;

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	SDL_Renderer* getRenderer() const { return renderer; }
private:
	GameStateMachine* m_pGameStateMachine;
	SDL_Window* window;
	SDL_Renderer* renderer;

	static Game* s_pInstance;

	bool m_bRunning;
};

typedef Game TheGame;
#endif /* defined(__Game__) */