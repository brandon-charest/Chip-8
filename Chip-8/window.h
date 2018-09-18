#pragma once
#include <SDL.h>
#include <memory>

static enum class windowState
{
	PLAY,
	QUIT
};

class window
{
public:

	window();
	~window();

	void const Init() const;
	void const Quit() const;

	static windowState getCurrentWindowState();
	static void setCurrentWindowState(windowState state);

private:
	void Clear();
	void Update();
	void const PlayLoop() const; 
	
	static std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> m_rendererPtr;
	static std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> m_windowPtr;	
	static SDL_Rect m_box;

	static windowState m_windowState;
	int const m_screenHeight;
	int const m_screenWidth;	
};

