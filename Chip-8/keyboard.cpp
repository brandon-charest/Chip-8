#include "keyboard.h"
#include "window.h"
#include <iostream>

keyboard::keyboard()
{
}


keyboard::~keyboard()
{
}

void keyboard::processInput()
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type) 
		{
		case SDL_KEYDOWN:
			keyDown(e.key.keysym.sym);
			break;

		case SDL_KEYUP:
			keyUp(e.key.keysym.sym);
			break;

		case SDL_QUIT:
			window::setCurrentWindowState(windowState::QUIT);
			break;

		default:
			break;
		}
	}
}

void keyboard::keyDown(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_ESCAPE:
		window::setCurrentWindowState(windowState::QUIT);
		break;

	case SDLK_x:
		std::cout << "'X' is pressed.\n";
		
		break;

	default:
		break;
	}
}

void keyboard::keyUp(SDL_Keycode key)
{
}
