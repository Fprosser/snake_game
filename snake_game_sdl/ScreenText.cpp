#include "ScreenText.h"

ScreenText::ScreenText(SDL_Color color, int x, int y, std::string text) : m_color(color), m_text(text)
{
	TTF_Init();

	font = TTF_OpenFont("assets/Game-Font.ttf", 24);

	if (font == NULL) {
		std::cout << TTF_GetError();
	}

	m_textSurface = TTF_RenderText_Solid(font, m_text.c_str(), m_color);

	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(TheGame::Instance()->getRenderer(), m_textSurface);

	if (font == NULL) {
		std::cout << TTF_GetError();
	}


	m_destRect = { x, y, m_textSurface->w, m_textSurface->h };

	SDL_RenderCopy(TheGame::Instance()->getRenderer(), textTexture, NULL, &m_destRect);


}

