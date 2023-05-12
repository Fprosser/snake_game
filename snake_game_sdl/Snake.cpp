#include "Snake.h"

Snake::Snake(vector<Body*> body) : mbody(body) {
	

}

void Snake::update() {
	float scale = 32.0f;

	Body* head = *mbody.begin();

	Body* tail = mbody.back();

	Vector2D newHeadPos = head->getPosition() + (mdirection * scale);
	
	tail->setPosition(newHeadPos);

}

void Snake::addBody(Body* body) {
	mbody.push_back(body);
}