#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "Game.h"
#include <string>
#include <iostream>

class ScreenText
{
public:
	ScreenText(SDL_Color color, int x, int y, std::string text);
private:
	TTF_Font* font; 
	SDL_Color m_color;
	SDL_Rect m_destRect;
	std::string m_text;
	SDL_Surface* m_textSurface;
	
};

