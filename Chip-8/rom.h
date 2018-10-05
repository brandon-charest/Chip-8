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

	void LoadRomFile();
	std::vector<char> GetBuffer();

private:	
	static std::vector<char> m_buffer;
	std::ifstream m_file;
	std::streampos m_size;

};

