#pragma once

#include "rom.h"
#include <cstdint>
#include <array>
#include <stack>

using std::stack;
using std::array;

class chip8
{
public:
	chip8();
	~chip8();

	bool drawFlag;
	void emulateCycle();
	void debugRender();
	void loadFromRom(string const fileName);

	static uint16_t const memory_start = 0x200;

	// Screen has a total of 2048 pixels (64 x 32)	
	array<uint8_t, 64 * 32> gfx;

	uint8_t get_pixel(int x, int y);

private:

	void make_beep();
	void clear_stack();
	void clear_registers();
	void clear_memory();
	void init();
	void load_fontset(array<uint8_t, 4096> memory, array<uint8_t, 80> fontset);

	uint16_t m_program_counter;
	// Chip 8 has 35 opcodes
	uint16_t m_opcode;
	uint16_t m_index_register;
	uint16_t m_stack_pointer;	

	//array<uint16_t, 16> m_stack;
	stack<uint16_t> m_stack;

	// Chip 8 has 15 8-bit general purpose registers.
	// the 16th register is used for the carry flag.	
	array<uint8_t, 16> m_V;

	// 4k memory
	array<uint8_t, 4096> m_memory;	
	uint8_t m_delay_timer;
	uint8_t m_sound_timer;

	
	
	uint8_t random_number() const;
};


