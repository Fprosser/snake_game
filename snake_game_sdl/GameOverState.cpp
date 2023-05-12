#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"


const string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update()
{
	for (int i = 0; i < (int)m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GameOverState::render()
{
	for (int i = 0; i < (int)m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}


void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

bool GameOverState::onEnter()
{
	if (!TextureManager::Instance()->load("./assets/gameover_background.png", "gameOverBackground", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("./assets/menu_button_spritesheet.png", "menubutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("./assets/number_sheet-300.png", "number_sheet", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* gameOverBackground = new AnimatedGraphic(new LoaderParams(0, 0, 640, 512, "gameOverBackground"), 1);
	m_gameObjects.push_back(gameOverBackground);
	GameObject* button1 = new MenuButton(new LoaderParams(250, 75, 96, 48, "menubutton"), s_gameOverToMain);
	m_gameObjects.push_back(button1);

	AnimatedGraphic* scoreText_ten = new AnimatedGraphic(new LoaderParams(295, 450, 16, 16, "number_sheet"), 10);
	AnimatedGraphic* scoreText_hundred = new AnimatedGraphic(new LoaderParams(275, 450, 16, 16, "number_sheet"), 10);

	m_scoreTextTen = scoreText_ten;
	m_scoreTextHundred = scoreText_hundred;


	std::cout << "entering GameOverState\n";
	return true;
}

bool GameOverState::onExit()
{
	for (int i = 0; i < (int)m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TextureManager::Instance()->clearFromTextureMap("resumebutton");
	TextureManager::Instance()->clearFromTextureMap("mainbutton");

	std::cout << "exiting GameOverState" << std::endl;
	return true;
}

