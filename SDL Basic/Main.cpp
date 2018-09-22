
#include <iostream>

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