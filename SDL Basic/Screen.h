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
	Uint32 *m_buffer2;

public:
	Screen();
	~Screen();

	bool init();
	bool processEvent();

	void update();
	void close();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void clear();
	void boxBlur();
};

