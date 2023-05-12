#pragma once
#include "SDL.h"
#include "SDL_joystick.h"
#include "Vector2D.h"
#include <iostream>
#include <vector>

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}

		return s_pInstance;
	}

	void update();
	void clean();
	bool getMouseButtonState(int buttonNumber);
	bool isKeyDown(SDL_Scancode key);
	void onKeyDown(SDL_Event event);
	Vector2D* getMousePosition();


private:
	InputHandler();
	~InputHandler();

	static InputHandler* s_pInstance;

	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);
	void onMouseMotion(SDL_Event event);


	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;
	const Uint8* m_keystates;
};

typedef InputHandler TheInputHandler;
