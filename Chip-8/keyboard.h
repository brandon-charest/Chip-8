#pragma once
#include "SDL.h"
#include <array>
class keyboard
{
public:
	keyboard();
	~keyboard();

	void processInput();
	// Chip 8 uses hex based keypad (0x0-0xF)	
	std::array<uint8_t, 16> keyState;
private:
	

	void keyEvent(SDL_Keycode key, uint8_t e);
	uint8_t keyEventHelper(uint8_t keyEvent);		
};

