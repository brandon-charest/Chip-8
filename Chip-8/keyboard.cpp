#include "keyboard.h"
#include "window.h"
#include <iostream>

keyboard::keyboard()
{	
}


keyboard::~keyboard()
{
}

void keyboard::processInput()
{
	SDL_Event sdlEvent;

	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_KEYDOWN:
		case SDL_KEYUP:			
			keyEvent(sdlEvent.key.keysym.scancode, sdlEvent.key.state);
			break;

		case SDL_QUIT:
			window::setCurrentWindowState(windowState::QUIT);
			break;

		default:
			break;
		}
	}
}

void keyboard::keyEvent(SDL_Scancode code, uint8_t keyEvent)
{
	// for debugging
	auto temp = keyEvent == SDL_PRESSED ? "Pressed" : "Released";
	switch (code)
	{
	case SDL_SCANCODE_ESCAPE:
		window::setCurrentWindowState(windowState::QUIT);
		break;

	case SDL_SCANCODE_X:
		std::cout << "'X' is " << temp << "\n";
		keyState[0x0] = keyEventHelper(keyEvent);
		break;

	case SDL_SCANCODE_1:
		std::cout << "'1' is " << temp << "\n";
		keyState[0x1] = keyEventHelper(keyEvent);
		break;

	case SDL_SCANCODE_2:
		std::cout << "'2' is " << temp << "\n";
		keyState[0x2] = keyEventHelper(keyEvent);
		break;

	case SDL_SCANCODE_3:
		std::cout << "'3' is " << temp << "\n";
		keyState[0x3] = keyEventHelper(keyEvent);
		break;

	case SDL_SCANCODE_Q:
		std::cout << "'Q' is " << temp << "\n";
		keyState[0x4] = keyEventHelper(keyEvent);
		break;

	case SDL_SCANCODE_W:
		std::cout << "'W' is " << temp << "\n";
		keyState[0x5] = keyEventHelper(keyEvent);
		break;

	caseSDL_SCANCODE_E:
		std::cout << "'E' is " << temp << "\n";
		keyState[0x6] = keyEventHelper(keyEvent);
		break;
	case SDL_SCANCODE_A:
		std::cout << "'A' is " << temp << "\n";
		keyState[0x7] = keyEventHelper(keyEvent);
		break;

	case SDL_SCANCODE_S:
		std::cout << "'S' is " << temp << "\n";
		keyState[0x8] = keyEventHelper(keyEvent);
		break;

	case SDL_SCANCODE_D:
		std::cout << "'D' is " << temp << "\n";
		keyState[0x9] = keyEventHelper(keyEvent);
		break;

	case SDL_SCANCODE_Z:
		std::cout << "'Z' is " << temp << "\n";
		keyState[0xA] = keyEventHelper(keyEvent);
		break;

	case SDL_SCANCODE_C:
		std::cout << "'C' is " << temp << "\n";
		keyState[0xB] = keyEventHelper(keyEvent);
		break;

	case SDL_SCANCODE_4:
		std::cout << "'4' is " << temp << "\n";
		keyState[0xC] = keyEventHelper(keyEvent);
		break;

	case SDL_SCANCODE_R:
		std::cout << "'R' is " << temp << "\n";
		keyState[0xD] = keyEventHelper(keyEvent);
		break;

	case SDL_SCANCODE_F:
		std::cout << "'F' is " << temp << "\n";
		keyState[0xE] = keyEventHelper(keyEvent);
		break;

	case SDL_SCANCODE_V:
		std::cout << "'V' is " << temp << "\n";
		keyState[0xF] = keyEventHelper(keyEvent);
		break;

	default:
		break;
	}
}

uint8_t keyboard::keyEventHelper(uint8_t keyEvent)
{
	return keyEvent == SDL_PRESSED ? SDL_PRESSED : SDL_RELEASED;
}

