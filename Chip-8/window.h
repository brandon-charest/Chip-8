#pragma once
#include <SDL.h>
#include <memory>

class window
{
public:

	window();
	~window();

	void const Init() const;
	void const Quit() const;

private:

	struct SDL_Deleter {
		void operator()(SDL_Surface*  ptr) { if (ptr) SDL_FreeSurface(ptr); }
		void operator()(SDL_Texture*  ptr) { if (ptr) SDL_DestroyTexture(ptr); }
		void operator()(SDL_Renderer* ptr) { if (ptr) SDL_DestroyRenderer(ptr); }
		void operator()(SDL_Window*   ptr) { if (ptr) SDL_DestroyWindow(ptr); }
		void operator()(SDL_RWops*    ptr) { if (ptr) SDL_RWclose(ptr); }
	};


	using m_windowPtr = std::unique_ptr<SDL_Window, SDL_Deleter>;
	using m_rendererPtr = std::unique_ptr<SDL_Renderer, SDL_Deleter>;
	
	SDL_Rect m_box;


	int const m_screenHeight;
	int const m_screenWidth;

	

protected:
	
};

