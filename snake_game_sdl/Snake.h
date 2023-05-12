#pragma once
#include "Body.h"
#include "Vector2D.h"
#include <vector>
class Snake
{
public:
	Snake(vector<Body*> body);
	void update();
	void addBody(Body* body);
	int length() { return mbody.size(); }

protected:
	vector<Body*> mbody;
	Vector2D mdirection = Vector2D(-1.0f, 0.0f);
};