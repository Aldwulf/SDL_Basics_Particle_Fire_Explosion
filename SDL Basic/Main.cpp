
#include <iostream>

#include <math.h>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"


using namespace std;

int main(int argc, char **argv)
{
	srand(time(NULL));

	Screen screen;

	Swarm swarm;

	if (screen.init() == false)
	{
		cout << "Failed to initialise SDL" << endl;
	}
	
	while (true)
	{
		// update particles
		// draw particles

		int elapsed = SDL_GetTicks();
		//screen.clear();
		swarm.update(elapsed);

		// generating colours
		unsigned char red = (1 + sin(elapsed * 0.001)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.003)) * 128;

		const Particle * const pParticles = swarm.getParticles(); // pointer to m_pParticles which is the array of particles

		// for each particle set their starting position and their colour for this frame
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticles[i];

			// set starting position
			int x = (particle.m_x + 1) * screen.SCREEN_WIDTH / 2;
			int y = particle.m_y * screen.SCREEN_WIDTH / 2 + screen.SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

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