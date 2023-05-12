#pragma once
#include "SDLGameObject.h"
#include <stdlib.h>

class Fruit : public SDLGameObject
{
public:
	Fruit(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	void setPosition(Vector2D newPosition);
	void setFrame(int score) {m_currentFrame = (rand() % 4);}

};

