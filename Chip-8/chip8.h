#pragma once
#include <cstdint>
#include <array>
using std::array;

#include <string>
using std::string;

class chip8
{
public:
	chip8();
	~chip8();

	bool drawFlag;
	void emulateCycle();
	void debugRender();
	bool loadApplication(string const fileName);

	// Screen has a total of 2048 pixels (64 x 32)	
	array<uint8_t, 64 * 32> gfx;

	// Chip 8 uses hex based keypad (0x0-0xF)	
	array<uint8_t, 16> key;

private:
	uint16_t m_program_counter;
	// Chip 8 has 35 opcodes
	uint16_t m_opcode;
	uint16_t m_index_register;
	uint16_t m_stack_pointer;	
	array<uint16_t, 16> m_stack;

	// Chip 8 has 15 8-bit general purpose registers.
	// the 16th register is used for the carry flag.	
	array<uint8_t, 16> m_V;

	// 4k memory
	array<uint8_t, 4096> m_memory;	
	uint8_t m_delay_timer;
	uint8_t m_sound_timer;

	void init();
};


