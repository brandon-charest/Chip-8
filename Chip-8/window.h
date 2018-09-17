#pragma once
#include <SDL.h>
#include <memory>

enum class windowState{PLAY,QUIT};

class window
{
public:

	window();
	~window();

	void const Init() const;
	void const Quit() const;

	windowState currentWindowState();

private:
	void Clear();
	void Update();

	
	static std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> m_rendererPtr;
	static std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> m_windowPtr;	
	static SDL_Rect m_box;

	windowState m_windowState;
	int const m_screenHeight;
	int const m_screenWidth;

	

protected:
	
};

