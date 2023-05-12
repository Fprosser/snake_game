#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "GameOverState.h"
#include <stdlib.h>
#include <windows.h>


const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	handleInput();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}

	Body* tail = m_Snake.back();
	m_Snake.pop_back();

	m_Snake.insert(m_Snake.begin(), tail);

	updateSnake(m_Snake);

	m_scoreTextTen->changeFrame(m_score);

	if (m_score > 9) {
		m_scoreTextHundred->changeFrame((int)(m_score / 10));
	}


	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	/*SDL_Color textColor = { 255,0,0 };
	string scoreText = to_string(m_score);

	ScreenText(textColor, 20, 20, scoreText);*/

	/*if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1]))) {
		TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
	}*/



}
void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	for (int i = 1; i < 19; i++) {
		int x = i * 32;
		int y1 = 32;
		int y2 = 448;

		SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 240, 238, 215, 255);
		SDL_RenderDrawLine(TheGame::Instance()->getRenderer(), x, y1, x, y2);
		SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 128, 128, 128, 255);
	}

	for (int i = 1 ; i < 15; i++) {
		int y = i * 32;
		int x1 = 32;
		int x2 = 576;

		SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 240, 238, 215, 255);
		SDL_RenderDrawLine(TheGame::Instance()->getRenderer(), x1, y, x2, y);
		SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 128, 128, 128, 255);
	}
}
bool PlayState::onEnter()
{
	if (!TextureManager::Instance()->load("./assets/playstate_background.png", "playstate_background", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	AnimatedGraphic* playstate_background = new AnimatedGraphic(new LoaderParams(0, 0, 640, 512, "playstate_background"), 1);
	m_gameObjects.push_back(playstate_background);

	Body* bodyA = new Body(new LoaderParams(192, 192, 32, 32));

	m_Snake.push_back(bodyA);


	for (int i = 0; i < m_Snake.size(); i++) {
		m_gameObjects.push_back(m_Snake[i]);
	}


	TextureManager::Instance()->load("./assets/fruit_sheet.png", "fruit", TheGame::Instance()->getRenderer());
	m_fruit = new Fruit(new LoaderParams(32, 32, 32, 32, "fruit"));

	m_gameObjects.push_back(m_fruit);

	if (!TextureManager::Instance()->load("./assets/score.png", "score", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TextureManager::Instance()->load("./assets/number_sheet.png", "number_sheet", TheGame::Instance()->getRenderer()))
	{
		return false;
	}


	
	AnimatedGraphic* scoreLabel = new AnimatedGraphic(new LoaderParams(200, 450, 80, 16, "score"), 1);
	AnimatedGraphic* scoreText_ten = new AnimatedGraphic(new LoaderParams(295, 450, 16, 16, "number_sheet"), 10);
	AnimatedGraphic* scoreText_hundred = new AnimatedGraphic(new LoaderParams(275, 450, 16, 16, "number_sheet"), 10);


	m_gameObjects.push_back(scoreLabel);
	m_gameObjects.push_back(scoreText_ten);
	m_gameObjects.push_back(scoreText_hundred);

	m_scoreTextTen = scoreText_ten;
	m_scoreTextHundred = scoreText_hundred;

	
	std::cout << "entering PlayState\n";

	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();
	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();
	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}

void PlayState::updateSnake(std::vector<Body*> Snake) {



	Body* head = Snake.front();

	Body* tail = Snake.back();

	float scale = 32.0f;

	Vector2D newHeadPos = head->getPosition() + (mdirection * scale);

	if (newHeadPos.getX() > 544) {

		newHeadPos.setX(32);
	}

	if (newHeadPos.getX() < 32) {
		newHeadPos.setX(544);
	}

	if (newHeadPos.getY() > 416) {

		newHeadPos.setY(32);
	}

	if (newHeadPos.getY() < 32) {
		newHeadPos.setY(416);
	}

	for (int i = 0; i < m_Snake.size()-1; i++) {
		if (newHeadPos.getX() == m_Snake[i]->getPosition().getX() && newHeadPos.getY() == m_Snake[i]->getPosition().getY()) {
			TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
			SoundManager::Instance()->play("./assets/game_over.wav");
		}
	}

	tail->setPosition(newHeadPos);

	Snake.insert(Snake.begin(), tail);

	

	if (m_fruitPos.getX() == newHeadPos.getX() && m_fruitPos.getY() == newHeadPos.getY()) {
		addBody();
		spawnFruit(m_fruit);
		m_score++;
		m_fruit->setFrame(m_score);
		SoundManager::Instance()->play("./assets/eat.wav");
	}

	

	
}

void PlayState::handleInput() {

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		if (mdirection.getY() != -1.0f) {
			mdirection = Vector2D(0.0f, 1.0f);
		}

	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		if (mdirection.getY() != 1.0f) {
			mdirection = Vector2D(0.0f, -1.0f);
		}
	}
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && !(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)))
	{
		if (mdirection.getX() != 1.0f) {
			mdirection = Vector2D(-1.0f, 0.0f);
		}
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) && !(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)))
	{
		if (mdirection.getX() != -1.0f) {
			mdirection = Vector2D(1.0f, 0.0f);
		}
		
	}

}

void PlayState::addBody() {

	float scale = 32.0f;
	Body* tempBody = new Body(new LoaderParams(500, 500, 32, 32));
	Body* tail = m_Snake.back();


	Vector2D newTailPos = tail->getPosition() - (mdirection * scale);

	tempBody->setPosition(newTailPos);
	m_gameObjects.push_back(tempBody);
	m_Snake.push_back(tempBody);
}

void PlayState::spawnFruit(Fruit* fruit) {


	float x = (rand() % 10 + 1)* 32;
	float y = (rand() % 10 + 1)* 32;

	fruit->setPosition(Vector2D(x, y));
	
	m_fruitPos = dynamic_cast<SDLGameObject*>(fruit)->getPosition();

}
