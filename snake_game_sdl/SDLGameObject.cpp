#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams), m_position(pParams ->getX(), pParams->getY()), m_velocity(0, 0), m_acceleration(0, 0) {
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_textureID = pParams->getTextureID();

	m_currentRow = 1;
	m_currentFrame = 0;

}

void SDLGameObject::draw()
{
	if (m_textureID != "") {
		TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
	}
	else {
		SDL_Rect box;
		
		box.x = m_position.getX();
		box.y = m_position.getY();
		box.w = m_width;
		box.h = m_height;
		SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 0, 0, 0, 255);
		SDL_RenderFillRect(TheGame::Instance()->getRenderer(), &box);
		SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 128, 128, 128, 255);

	}
	
}

void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}

void SDLGameObject::clean()
{
	cout << "clean game object";
}