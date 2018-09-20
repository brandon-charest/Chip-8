#pragma once
#include "rom.h"
#include "keyboard.h"
#include "window.h"
#include <cstdint>
#include <array>
#include <stack>

class chip8
{
public:
	chip8();
	~chip8();

	bool drawFlag;
	void emulateCycle();
	void init();
	void debugRender();
	void loadRomToMemory(std::vector<char> mem);
	static uint16_t const memory_start = 0x200;

	uint8_t get_pixel(int x, int y);

private:
	void make_beep();
	void clear_stack();
	void clear_registers();
	void clear_memory();

	void load_fontset(std::array<uint8_t, 4096> memory, std::array<uint8_t, 80> fontset);

	window m_screen;
	keyboard m_keyboard;

	uint16_t m_program_counter;
	// Chip 8 has 35 opcodes
	uint16_t m_opcode;
	uint16_t m_index_register;
	uint16_t m_stack_pointer;	

	//array<uint16_t, 16> m_stack;
	std::stack<uint16_t> m_stack;

	// Chip 8 has 15 8-bit general purpose registers.
	// the 16th register is used for the carry flag.	
	std::array<uint8_t, 16> m_V;

	// 4k memory
	std::array<uint8_t, 4096> m_memory;	
	uint8_t m_delay_timer;
	uint8_t m_sound_timer;

	
	
	uint8_t random_number() const;
};


