#pragma once
#include "SDL.h"

class keyboard
{
public:
	keyboard();
	~keyboard();

	void processInput();

private:

	void keyEvent(SDL_Keycode key, uint8_t e);
	uint8_t keyEventHelper(uint8_t keyEvent);
	
	uint8_t keyState[16];
};

