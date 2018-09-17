#include "keyboard.h"



keyboard::keyboard()
{
}


keyboard::~keyboard()
{
}

void const keyboard::processInput()
{
	SDL_Event inputEvent;

	

	while (SDL_PollEvent(&inputEvent))
	{
		switch (inputEvent.type)
		{
		case SDL_QUIT:
			
		default:
			break;
		}
	}
}
