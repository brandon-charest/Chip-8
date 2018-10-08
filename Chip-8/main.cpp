#include "window.h"
#include "chip8.h"

//TODO: Fix Keyboard input array crashing
//		seems to be caused by graphics rendering.....
//TODO: Graphics rendering
//TODO: Sound
//TODO: Rom selection screen

int main(int argc, char *argv[])
{
	chip8 chip8;
	window window;

	window.Init();
	chip8.init();
	chip8.play_loop();


	return 0;
}

