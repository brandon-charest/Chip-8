#include "window.h"
#include "errors.h"
#include "chip8.h"
#include "keyboard.h"
#include <iostream>
#include <GL\glew.h>
#include <SDL_image.h>

std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window::m_windowPtr = std::unique_ptr<SDL_Window, void(*)(SDL_Window*)>(nullptr, SDL_DestroyWindow);
std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> window::m_rendererPtr = std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)>(nullptr, SDL_DestroyRenderer);

windowState window::m_windowState;


window::window() : m_screenHeight(64), m_screenWidth(128)
{
	window::m_windowState = windowState::PLAY;
}

window::~window()
{
}

void window::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL could not initialize! SDL_ERROR: " << SDL_GetError() << "\n";
	}

	//Creates window*
	m_windowPtr.reset(SDL_CreateWindow("Chip 8", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (m_screenWidth * X_SCALE) / 2, (m_screenHeight * Y_SCALE) / 2, SDL_WINDOW_OPENGL));
	if (m_windowPtr == nullptr)
	{
		fatalError("SDL window could not be created!");
	}
	else
	{
		// create renderer for window
		m_rendererPtr.reset(SDL_CreateRenderer(m_windowPtr.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
		SDL_RenderSetScale(m_rendererPtr.get(), X_SCALE, Y_SCALE);

		if (m_rendererPtr == nullptr)
		{
			fatalError("Failed to create renderer!");
		}
		else
		{
			// Init renderer color
			SDL_SetRenderDrawColor(m_rendererPtr.get(), 0xFF, 0xFF, 0xFF, 0xFF);

			uint8_t imgFlag = IMG_INIT_PNG;

			if (!(IMG_Init(imgFlag) & imgFlag))
			{
				fatalError(IMG_GetError());
			}
		}
	}


	SDL_GLContext glContext = SDL_GL_CreateContext(m_windowPtr.get());
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
}


void window::Quit()
{
	SDL_DestroyRenderer(m_rendererPtr.get());
	SDL_DestroyWindow(m_windowPtr.get());

	m_rendererPtr.reset();
	m_windowPtr.reset();

	SDL_Quit();
}

void window::setCurrentWindowState(windowState state)
{
	window::m_windowState = state;
}

windowState window::getCurrentWindowState()
{
	return m_windowState;
}

void window::Clear()
{
	SDL_RenderClear(m_rendererPtr.get());
}

void window::Update()
{
	SDL_RenderPresent(m_rendererPtr.get());
}

void window::PlayLoop()
{
	chip8 myChip8;
	keyboard keyboard;

	while (window::m_windowState != windowState::QUIT)
	{
		myChip8.emulateCycle();

		if (myChip8.drawFlag)
		{

		}

		//keyboard.processInput();
	}

	window::Quit();
}

void window::clearGFx()
{
	gfx.fill(0);
}
