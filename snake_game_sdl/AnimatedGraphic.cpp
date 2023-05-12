#include "AnimatedGraphic.h"
#include "SDL.h"

//constructor for AnimatedGraphic class
AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int offset) : SDLGameObject(pParams), m_offset(offset)
{

}

void AnimatedGraphic::draw()
{
	SDLGameObject::draw();
}

//update function of animated graphic class
void AnimatedGraphic::update()
{
	//m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % 6/*m_numFrames*/));
	//not animating currently so set to 0;
}

void AnimatedGraphic::clean()
{
	SDLGameObject::clean();
}

void AnimatedGraphic::changeFrame(int input) {
	m_currentFrame = input % m_offset;
}