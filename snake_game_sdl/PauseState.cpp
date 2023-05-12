#include "PauseState.h"

const std::string PauseState::s_pauseID = "Pause";

void PauseState::s_pauseToMain() {

	TheGame::Instance()->getStateMachine()->changeState(new MenuState());

}

void PauseState::s_resumePlay() {
	TheGame::Instance()->getStateMachine()->popState();
}


void PauseState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PauseState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter()
{
	if (!TextureManager::Instance()->load("./assets/resume_button_spritesheet.png", "resumebutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("./assets/menu_button_spritesheet.png", "menubutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 96, 48, "menubutton"), s_pauseToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 96, 48, "resumebutton"), s_resumePlay);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}

bool PauseState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("resumebutton");
	TextureManager::Instance()->clearFromTextureMap("mainbutton");

	// reset the mouse button states to false
	std::cout << "exiting PauseState\n";
	return true;
}