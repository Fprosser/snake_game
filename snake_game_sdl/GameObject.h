#pragma once
#include <iostream>
#include "LoaderParams.h"
#include "SDL.h"
#include "TextureManager.h"

using namespace std;
class GameObject
{

public:

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;


	/*void draw() { std::cout << "draw game object"; }
	void update() { std::cout << "update game object"; }
	void clean() { std::cout << "clean game object"; }*/
protected:
	GameObject(const LoaderParams* pParams) {}
	//virtual ~GameObject() {}

};
