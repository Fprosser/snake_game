#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

	//initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		window = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		std::cout << "\n" << "window created";

		//if window was created successfully
		if (window != 0) {
			std::cout << "\n" << "renderer created";
			renderer = SDL_CreateRenderer(window, -1, 0);

			if (renderer != 0) {
				std::cout << "\n" << "renderer successfully created";
				
			}
			else {
				std::cout << "\n" << "renderer creation failed";
				return false;
			}
		}
		else {
			std::cout << "\n" << "window creation failed";
			return false;
		}

	}
	else {
		std::cout << "\n" << "sdl couldn't initialize";
		return false;
	}


	std::cout << "\n" << "SDL init successful"; //start the main loop
	m_bRunning = true;

	//Instantiate Texture Manager
	TextureManager* textureManager = TextureManager::Instance();

	SoundManager* soundManager = SoundManager::Instance();


	//m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 32, 32, "animate")));
	//m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 32, 32, "animate")));

	//initialize gamestate manager

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());

	return true;

}

void Game::render() {
	//clear the renderer to draw the color
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);

	m_pGameStateMachine->render();

	//draw game objects vector
	/*for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}*/

	//Draw to the screen
	SDL_RenderPresent(renderer);

	SDL_Delay(50);

}

void Game::handleEvents() {
	TheInputHandler::Instance()->update();


	//std::cout << TheInputHandler::Instance()->getMousePosition()->getX() << "," << TheInputHandler::Instance()->getMousePosition()->getY() << '\n';

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::update() {

	//update our game objects
	//for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	//{
	//	m_gameObjects[i]->update();
	//}

	m_pGameStateMachine->update();

	SDL_Delay(50);

}

void Game::clean() {

	//clean up SDL
	std::cout << "\n" << "cleaning up";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::running() { return m_bRunning; }

void Game::quit() {
	m_bRunning = false;
}

