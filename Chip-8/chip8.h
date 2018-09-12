#pragma once
#include <cstdint>
class chip8
{
public:
	chip8();
	~chip8();

	bool drawFlag;
	void emulateCycle();
	void debugRender();
	bool loadApplication(char* const fileName);

	// Screen has a total of 2048 pixels (64 x 32)
	uint8_t gfx[64 * 32];

	// Chip 8 uses hex based keypad (0x0-0xF)
	uint8_t key[16];

private:
	uint16_t m_program_counter;
	uint16_t m_opcode;
	uint16_t m_index_register;
	uint16_t m_stack_pointer;
	uint16_t m_stack[16];

	// Chip 8 has 15 8-bit general purpose registers.
	// the 16th register is used for the carry flag.
	uint8_t m_V[16];

	// 4k memory
	uint8_t m_memory[4096];
	uint8_t m_delay_timer;
	uint8_t m_sound_timer;

	void init();
};

