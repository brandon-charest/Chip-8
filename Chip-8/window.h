#pragma once
#include <SDL.h>
#include <memory>
#include <cassert>
#include <vector>
#include <array>
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
	void const clearGFx();
	void const Draw();

	static void setCurrentWindowState(windowState state);
	// Screen has a total of 2048 pixels (64 x 32)	
	std::array<uint8_t, 64 * 32> gfx;
	
private:
	void Clear();
	void Update();
	void const PlayLoop() const; 
	
	std::vector<uint8_t> m_buffer;

	static std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> m_rendererPtr;
	static std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> m_windowPtr;	
	static SDL_Rect m_box;

	static windowState m_windowState;
	int const m_screenHeight;
	int const m_screenWidth;
	int const X_SCALE = 6;
	int const Y_SCALE = 6;
};

