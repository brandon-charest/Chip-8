#pragma once
#include "SDL.h"

class keyboard
{
public:
	keyboard();
	~keyboard();

	void processInput();
private:
	void keyDown(SDL_Keycode key);
	void keyUp(SDL_Keycode key);
};

