#include "main.h"
#include "Game.h"
#include "SDL.h"
#include <iostream>

/*
* The game's main loop.
* First we instantiate the game as a singleton. if the pointer to TheGame has been created we enter the main loop.
* loop while our running() function returns true.
* In the main loop we start the Frame timer, Handle events, update and render the game's state.
* At the end of the loop we delay SDL by to give us a desired 60 updates / second.
* If a pointer to TheGame isn't create then we throw an error to the console.
* When the game is quit out of we clean up out instance.
*
*/

Game* g_game = 0;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
int main(int argc, char* argv[])
{
	Uint32 frameStart, frameTime;


	std::cout << "game init attempt....\n";


	if (TheGame::Instance()->init("Snake!", 100, 100, 480, 608, false)) {
		std::cout << "game init success! \n";
		while (TheGame::Instance()->running()) {
			frameStart = SDL_GetTicks();


			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME) {
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else {
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}

	std::cout << "game closing...\n";
	TheGame::Instance()->clean();

	return 0;
}