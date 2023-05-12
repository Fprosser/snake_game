#pragma once
#include "SDLGameObject.h"
class Body : public SDLGameObject
{
public:
	Body(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
	void handleInput();
	void setPosition(Vector2D newPos);
};

