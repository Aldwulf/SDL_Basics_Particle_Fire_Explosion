
#include <iostream>

#include <SDL.h>

using namespace std;

int main(int argc, char **argv)
{
	// constants for screen size
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL_Init failed" << SDL_GetError() << endl;
		return 1;
	} // check whether it is initialised or not and return error


	// create an SDL window
	SDL_Window *window = SDL_CreateWindow("Particle_FIre_Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		SDL_Quit();
		return 2;
	}

	SDL_Event someEvent;
	

	bool quit = false;
	while (!quit)
	{
		// update particles
		// draw particles
		// check for events/messages
		
		while (SDL_PollEvent(&someEvent))
		{
			if (someEvent.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit(); // quit SDL
	system("pause");
	return 0;
}