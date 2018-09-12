#include "rom.h"



rom::rom()
{
}

rom::rom(std::string & filename) : m_filename(filename)
{
}


rom::~rom()
{
	if (m_buffer)
	{
		delete[] m_buffer;
	}
}

void rom::openFile()
{
}

rom& rom::operator=(rom& const r)
{
	if (this != &r)
	{
		this->m_filename = r.m_filename;
	}

	return *this;
}

bool rom::operator >> (uint8_t & c)
{
	c = m_buffer[m_pos];
	++m_pos;

	return m_pos < m_size;
}
