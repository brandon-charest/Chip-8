#include "rom.h"
#include "chip8.h"
#include "errors.h"
rom::rom()
{
	m_file.open(GAME, std::ios::in|std::ios::binary|std::ios::ate);	
}

rom::rom(std::string & fileName)
{
	m_file.open(fileName, std::ios::in | std::ios::binary | std::ios::ate);
}

rom::~rom()
{
	m_file.close();
}

void rom::LoadRomFile()
{
	
	if (m_file.is_open())
	{
		std::vector<char> m_buffer((std::istreambuf_iterator<char>(m_file)), std::istreambuf_iterator<char>());		
		std::cout << "File load into system memory.\n";
	}
	else
	{
		fatalError("Unable to load file.");
	}
}

std::vector<char> rom::GetBuffer()
{
	return m_buffer;
}


