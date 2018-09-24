#include "Screen.h"



Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL)
{
}


Screen::~Screen()
{
}

bool Screen::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//cout << "SDL_Init failed" << SDL_GetError() << endl;
		return false;
	} // check whether it is initialised or not and return error


	// create an SDL window
	m_window = SDL_CreateWindow("Particle_FIre_Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (m_window == NULL)
	{
		SDL_Quit();
		return false;
	} // if no window then quit

	// create an SDL renderer and synchronise it with the screen refresh
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	// create SDL texture
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	// if there is an error NULL is returned
	if (m_renderer == NULL) { SDL_DestroyWindow(m_window); SDL_Quit(); return false; }
	if (m_texture == NULL) { SDL_DestroyRenderer(m_renderer); SDL_DestroyWindow(m_window); SDL_Quit(); return false; }

	// allocate memory for the screen; each pixel requires 32 bits with SDL_PIXELFORMAT_RGBA8888 in texture; Uint32 is defined by SDL
	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	// set memory
	memset(m_buffer, 0x00, SCREEN_WIDTH*SCREEN_HEIGHT * sizeof(Uint32));



	return true;
}

bool Screen::processEvent()
{
	SDL_Event someEvent;

	while (SDL_PollEvent(&someEvent))
	{
		if (someEvent.type == SDL_QUIT)
		{
			return false;
		}
	}
	return true;
}

// copy pixels to a buffer, clear renderer (why not do this first?),  pass buffer to renderer, present renderer on screen
void Screen::update()
{
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::close()
{
	delete[] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit(); // quit SDL
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
	// pixels outside the screen are not plotted
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) { return; }

	// R G B Alpha
	Uint32 colour = 0;

	colour += red;
	colour <<= 8;
	colour += green;
	colour <<= 8;
	colour += blue;
	colour <<= 8;
	colour += 0xFF;

	m_buffer[(y*SCREEN_WIDTH) + x] = colour;
}

void Screen::clear()
{
	memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT * sizeof(Uint32));
}