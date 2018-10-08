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

	static constexpr uint16_t const MAX_MEMORY = 4096;
	static constexpr uint8_t const MAX_REGISTERS = 16;
	static constexpr uint16_t const MEMORY_START = 0x200;

	static bool drawFlag;

	chip8();
	~chip8();
	
	void emulateCycle();
	void init();
	void play_loop();
	void debugRender();	

	uint8_t get_pixel(int x, int y);

private:
	void make_beep();
	void clear_stack();
	void clear_registers();
	void clear_memory();
	void loadRomToMemory(std::vector<char> &memblock);
	void load_fontset(std::array<uint8_t, 80> fontset);

	window m_screen;	
	keyboard m_keyboard;
	rom m_rom;

	// 4k memory
	static std::array<uint8_t, MAX_MEMORY> m_memory;

	static uint16_t m_program_counter;	

	//array<uint16_t, 16> m_stack;
	static std::stack<uint16_t> m_stack;

	// Chip 8 has 15 8-bit general purpose registers.
	// the 16th register is used for the carry flag.	
	static std::array<uint8_t, MAX_REGISTERS> m_V;

	// Chip 8 has 35 opcodes
	uint16_t m_opcode;

	uint16_t m_index_register;
	uint8_t m_delay_timer;
	uint8_t m_sound_timer;		
	uint8_t random_number() const;

};


