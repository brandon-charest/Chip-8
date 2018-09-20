#include "rom.h"
#include "chip8.h"
#include "errors.h"
rom::rom()
{
	m_file.open(GAME, std::ios::in|std::ios::binary|std::ios::ate);
}

rom::rom(std::string & fileName)
{
}

rom::~rom()
{
	m_file.close();
}

void rom::LoadRomFile()
{

	if (m_file.is_open())
	{
		m_size = m_file.tellg();
		m_buffer.push_back(m_size);
		m_file.seekg(0, std::ios::beg);
		m_file.read(m_buffer.data(), m_size);
		m_file.close();

		std::cout << "File load into memory success.\n";
	}
	else
	{
		fatalError("Unable to load file.");
	}
}

std::vector<unsigned char> rom::GetBuffer()
{
	return m_buffer;
}


