#pragma once
#include <fstream>
#include <iostream>
#include <vector>
class rom
{
public:
	rom();
	rom(std::string &fileName);
	~rom();

	void LoadRomFile();
	std::vector<char> GetBuffer();
private:

	std::vector<char> m_buffer;
	std::ifstream m_file;
	std::streampos m_size;
	const std::string GAME = "Roms/INVADERS";
};

