#include "Fruit.h"

Fruit::Fruit(const LoaderParams* pParams) : SDLGameObject(pParams) {

}

void Fruit::draw() {
	SDLGameObject::draw();
}

void Fruit::update() {
	SDLGameObject::update();
}

void Fruit::clean() {
	SDLGameObject::clean();
}

void Fruit::setPosition(Vector2D newPosition) {
	m_position = newPosition;
}



