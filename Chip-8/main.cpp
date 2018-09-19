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
	window chipWindow;

	chip8.init();
	chipWindow.Init();

	return 0;
}

