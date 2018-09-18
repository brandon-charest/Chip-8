#include "window.h"
#include "errors.h"
#include "chip8.h"
#include "keyboard.h"
#include <iostream>
#include <GL\glew.h>


std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window::m_windowPtr = std::unique_ptr<SDL_Window, void(*)(SDL_Window*)>(nullptr, SDL_DestroyWindow);
std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> window::m_rendererPtr = std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)>(nullptr, SDL_DestroyRenderer);

windowState window::m_windowState;

window::window() : m_screenHeight(800), m_screenWidth(600) 
{

	window::m_windowState = windowState::PLAY;
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

	//Creates window*
	m_windowPtr.reset(SDL_CreateWindow("Chip 8", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_screenWidth, m_screenHeight, SDL_WINDOW_OPENGL));
	if (m_windowPtr == nullptr)
	{	
		fatalError("SDL window could not be created!");
	}

	m_rendererPtr.reset(SDL_CreateRenderer(m_windowPtr.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
	if (m_rendererPtr == nullptr)
	{
		fatalError("Failed to create renderer!");
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

	window::PlayLoop();
}


void const window::Quit() const
{

	SDL_DestroyRenderer(m_rendererPtr.get());
	SDL_DestroyWindow(m_windowPtr.get());

	m_rendererPtr.reset();
	m_windowPtr.reset();

	SDL_Quit();
}

windowState window::getCurrentWindowState()
{
	return window::m_windowState;
}

void window::setCurrentWindowState(windowState state)
{
	window::m_windowState = state;
}


void window::Clear()
{	
	SDL_RenderClear(m_rendererPtr.get());
}

void window::Update()
{
	SDL_RenderPresent(m_rendererPtr.get());
}

void const window::PlayLoop() const
{
	chip8 myChip8;
	keyboard keyboard;
	int quit = 0;

	while (window::m_windowState != windowState::QUIT)
	{
		//myChip8.emulateCycle();
		keyboard.processInput();
	}	

	window::Quit();
}
