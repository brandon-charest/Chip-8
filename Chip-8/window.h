#pragma once
#include <SDL.h>
#include <memory>
#include <cassert>
#include <vector>
#include <array>
enum class windowState
{
	PLAY,
	QUIT
};

class window
{
	static constexpr uint8_t const SCREEN_WIDTH = 64;
	static constexpr uint8_t const SCREEN_HEIGHT = 32;
	static constexpr uint8_t const PIXEL_SIZE = 12;
public:

	window();
	~window();

	void Init();
	void Quit();
	void clearGFx();
	void Draw();
	
	static void setCurrentWindowState(windowState state);
	windowState getCurrentWindowState();
	// Screen has a total of 2048 pixels (64 x 32)	
	std::array<uint8_t, SCREEN_WIDTH * SCREEN_HEIGHT> gfx;
	
private:
	void Clear();
	void Update();
	
	std::vector<uint8_t> m_buffer;

	static std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> m_rendererPtr;
	static std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> m_windowPtr;	
	static std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> m_texturePtr;
	static SDL_Rect m_screenRec;
	static windowState m_windowState;
	
};

