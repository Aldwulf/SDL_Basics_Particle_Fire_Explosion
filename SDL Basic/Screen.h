#pragma once

#include <SDL.h>
#include <iostream>

class Screen
{
public:
	// constants for screen size
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;

public:
	Screen();
	~Screen();

	bool init();
	bool processEvent();

	void close();
};

