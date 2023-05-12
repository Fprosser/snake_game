#pragma once
#ifndef __PLAYSTATE__
#define __PLAYSTATE__
#include <vector>
#include "GameState.h"
#include "GameObject.h"
#include "Body.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "SoundManager.h"
#include "AnimatedGraphic.h"
#include "Fruit.h"

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }

	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
	void updateSnake(std::vector<Body*> Snake);
	void handleInput();
	void addBody();
	void spawnFruit(Fruit* fruit);
	int getScore() { return m_score; }

private:
	static const std::string s_playID;

	std::vector<GameObject*> m_gameObjects;
	AnimatedGraphic* m_scoreTextTen;
	AnimatedGraphic* m_scoreTextHundred;
	Vector2D m_fruitPos = Vector2D(32.0f, 32.0f);
	std::vector<Body*> m_Snake;
	Vector2D mdirection = Vector2D(-1.0f, 0.0f);
	Fruit* m_fruit;
	int m_score = 0;

};

#endif // !__PLAYSTATE__