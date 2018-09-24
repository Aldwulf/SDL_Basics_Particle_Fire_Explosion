
#include <iostream>

#include <math.h>
#include <SDL.h>
#include "Screen.h"


using namespace std;

int main(int argc, char **argv)
{
	Screen screen;

	if (screen.init() == false)
	{
		cout << "Failed to initialise SDL" << endl;
	}
	
	while (true)
	{
		// update particles
		// draw particles
		int elapsed = SDL_GetTicks();
		unsigned char red = (1 + sin(elapsed * 0.001)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.003)) * 128;

		for (int y = 0; y < screen.SCREEN_HEIGHT; y++)
		{
			for (int x = 0; x < screen.SCREEN_WIDTH; x++)
			{
				screen.setPixel(x, y, red, green, blue);
			}
		}

		screen.setPixel(400, 300, 255, 255, 255);

		// draw screen
		screen.update();

		// check for events/messages
		if (screen.processEvent() == false)
		{
			break;
		}
		
	}

	screen.close();
	
	system("pause");
	return 0;
}