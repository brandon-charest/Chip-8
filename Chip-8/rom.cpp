#include "rom.h"
#include "chip8.h"
#include "errors.h"

std::vector<char> rom::m_buffer;

rom::rom()
{
	m_file.open(GAME, std::ios::in | std::ios::binary | std::ios::ate);
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
		
		m_file.seekg(0, std::ios_base::end);
		m_size = m_file.tellg();
		
		if (m_size > chip8::MAX_MEMORY - 512)
		{
			fatalError("File is too large to load!");
		}
		else
		{
			m_buffer.resize(m_size);

			m_file.seekg(0, std::ios::beg);
			m_file.read(&m_buffer[0], m_size);

			std::cout << "File load into system memory.\n";
		}		
	}
	else
	{
		fatalError("Unable to load file!");
	}
}

std::vector<char> rom::GetBuffer()
{
	return this->m_buffer;
}


