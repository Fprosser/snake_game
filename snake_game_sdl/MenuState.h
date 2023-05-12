#pragma once
#include "GameState.h"
#include "Game.h"
#include "GameObject.h"
#include "MenuButton.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include <vector>
#include <iostream>

class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }
private:
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
	map<string, SDL_Texture*> m_textureMap;

	static void s_menuToPlay();
	static void s_exitFromMenu();

};

