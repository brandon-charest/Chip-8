#pragma once
#include <fstream>
#include <iostream>
#include <vector>


std::string const GAME = "Roms/PONG2";

class rom
{
public:
	rom();
	rom(std::string &fileName);
	~rom();

	char* memblock;
	std::vector<char> m_buffer;
	void LoadRomFile();
	void load_game(std::array<uint8_t, 4096> mem, char* memblock);
	void load_file();
	std::vector<char> GetBuffer();
private:
	std::ifstream file;
	std::streampos size;



	
	std::ifstream m_file;
	std::streampos m_size;

};

