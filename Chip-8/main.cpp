#include "window.h"
#include "chip8.h"

//TODO: Fix OpCodes
//TODO: Graphics rendering
//TODO: Sound

int main(int argc, char *argv[])
{
	chip8 chip8;
	window window;

	window.Init();
	chip8.init();
	chip8.play_loop();


	return 0;
}

