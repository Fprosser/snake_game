#pragma once

#ifndef __AnimatedGraphic__
#define __AnimatedGraphic__

#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
	int m_animSpeed;

public:
	AnimatedGraphic(const LoaderParams* pParams, int offset);

	void update();
	void draw();
	void clean();
	void changeFrame(int input);
	int getOffset() { return m_offset; }

private:
	int m_offset;
	int m_input;
};

#endif //defined(__AnimatedGraphic__)