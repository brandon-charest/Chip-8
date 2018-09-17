#include "window.h"
#include "errors.h"
#include <iostream>
#include <GL\glew.h>


window::window() : m_screenHeight(64), m_screenWidth(32) 
{
	m_windowState = windowState::PLAY;
}

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


	//Creates window*
	window.reset(SDL_CreateWindow("Chip 8", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_screenWidth, m_screenHeight, SDL_WINDOW_OPENGL));
	if (!window)
	{	
		fatalError("SDL window could not be created!");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(window.get());
	if (!glContext)
	{
		fatalError("SDL_GL Contect could not be created!");
	}

	//handles extentions
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		fatalError("Could not initialize glew!");
	}

	//Tells SDL to double buffer, one window drawn and one window cleared
	//helps with screen flicker, double buffer might be on by default
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}


void const window::Quit() const
{
	SDL_Quit();
}
