#include "window.h"
#include <iostream>



window::window() : m_screenHeight(64), m_screenWidth(32) 
{}

window::~window()
{
}

void const window::Init() const
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL could not initialize! SDL_ERROR: " << SDL_GetError() << "\n";
	}

	m_windowPtr window;
	m_rendererPtr renderer;


	window.reset(SDL_CreateWindow("Chip 8", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_screenWidth, m_screenHeight, NULL));

	if (!window)
	{
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

}


void const window::Quit() const
{
	SDL_Quit();
}
