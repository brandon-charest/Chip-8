#include "window.h"
#include "chip8.h"
//TODO: Finish opcodes
//TODO: Finish way to load roms
//TODO: Graphics rendering
//TODO: Sound
//TODO: create roms???

int main(int argc, char *argv[])
{
	chip8 chip8;
	window window;

	window.Init();
	chip8.init();
	chip8.play_loop();


	return 0;
}

