#include "rom.h"
#include "chip8.h"
#include "errors.h"
//std::vector<char> m_buffer = std::vector<char>{};

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
		//std::vector<char> m_buffer((std::istreambuf_iterator<char>(m_file)), std::istreambuf_iterator<char>());
		m_file.seekg(0, std::ios_base::end);
		std::streampos fileSize = m_file.tellg();
		
		m_buffer.resize(fileSize);

		m_file.seekg(0, std::ios::beg);
		m_file.read(&m_buffer[0], fileSize);

		std::cout << "File load into system memory.\n";

	}
	else
	{
		//fatalError("Unable to load file.");
	}
}

void rom::load_game(std::array<uint8_t, 4096> mem, char * memblock)
{
	for (int i = 0; i < size; ++i)
		mem[i + 512] = memblock[i];
}

void rom::load_file()
{
	if (file.is_open())
	{
		size = file.tellg();
		memblock = new char[size];
		file.seekg(0, std::ios::beg);
		file.read(memblock, size);
		file.close();

		std::cout << "The entire file content is in memory." << std::endl;
	}
	else
		std::cout << "Unable to open file." << std::endl;
}

std::vector<char> rom::GetBuffer()
{
	return this->m_buffer;
}


