#include "rom.h"

rom::rom()
{
	file.open(game, std::ios::in|std::ios::binary|std::ios::ate);
}

rom::~rom()
{
	file.close();
}

void rom::LoadRomFile()
{
	if (file.is_open())
	{

	}
}


