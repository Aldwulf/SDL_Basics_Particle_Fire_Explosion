
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
	} // if no window then quit

	// create an SDL renderer and synchronise it with the screen refresh
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	// create SDL texture
	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	// if there is an error NULL is returned
	if (renderer == NULL) { SDL_DestroyWindow(window); SDL_Quit(); cout << SDL_GetError() << endl; return 3; }
	if (texture == NULL) { SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); SDL_Quit(); cout << SDL_GetError() << endl; return 4; }

	// allocate memory for the screen; each pixel requires 32 bits with SDL_PIXELFORMAT_RGBA8888 in texture; Uint32 is defined by SDL
	Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	// set memory
	memset(buffer, 0xFF, SCREEN_WIDTH*SCREEN_HEIGHT * sizeof(Uint32));

	// copy pixels to a buffer, clear renderer (why not do this first?),  pass buffer to renderer, present renderer on screen
	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);



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

	delete[] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit(); // quit SDL
	system("pause");
	return 0;
}