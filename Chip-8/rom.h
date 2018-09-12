#pragma once
#include <string>
using std::string;
#include <fstream>
class rom
{
public:
	rom();
	rom(string &filename);
	~rom();

	void openFile();

	rom& operator=(rom& const r);
	bool operator >> (uint8_t& c);
private:
	string m_filename;
	std::ifstream m_file;
	int m_pos;
	int m_size;
	char* m_buffer = nullptr;
};

