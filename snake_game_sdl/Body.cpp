#include "Body.h"
#include "InputHandler.h"

Body::Body(const LoaderParams* pParams) : SDLGameObject(pParams) {

}

void Body::draw() {
	SDLGameObject::draw();
}

void Body::update() {

	SDLGameObject::update();

}

void Body::handleInput() {

}

void Body::clean() {

}

void Body::setPosition(Vector2D newPos) {
	m_position = newPos;
}