#pragma once
#include <fstream>
#include <iostream>
class rom
{
public:
	rom();
	~rom();

	void LoadRomFile();
	void LoadGame();

private:
	std::ifstream file;
	std::streampos size;
	const std::string game = "Roms/INVADERS";
};

