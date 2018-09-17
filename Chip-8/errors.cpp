#include "errors.h"
#include <iostream>
#include <SDL.h>



void fatalError(std::string errorString)
{
	std::cout << errorString << "\n";
	std::cout << "Enter any key to quit...";

	int x;
	std::cin >> x;

	SDL_Quit();
}
