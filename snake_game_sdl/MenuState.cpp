#include "MenuState.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter() {
	if (!TextureManager::Instance()->load("./assets/start_button_spritesheet.png", "playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TextureManager::Instance()->load("./assets/background_menu.png", "background_menu", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TextureManager::Instance()->load("./assets/exit_button_spritesheet.png", "exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}


	if (!TextureManager::Instance()->load("./assets/menu_title.png", "menuTitle", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* background = new AnimatedGraphic(new LoaderParams(0, 0, 640, 512, "background_menu"), 1);

	GameObject* title = new AnimatedGraphic(new LoaderParams(200, 100, 222, 55, "menuTitle"), 1);

	GameObject* button1 = new MenuButton(new LoaderParams(256, 200, 96, 48, "playbutton"), s_menuToPlay);

	GameObject* button2 = new MenuButton(new LoaderParams(256, 275, 96, 48, "exitbutton"), s_exitFromMenu);


	m_gameObjects.push_back(background);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	m_gameObjects.push_back(title);
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("playbutton");
	TextureManager::Instance()->clearFromTextureMap("exitbutton");
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());

}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}