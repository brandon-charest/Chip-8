#include "chip8.h"
#include <iostream>
/*
see http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#2.4
for more info

Example of chip 8 fonts
"0"			Binary			Hex
****		11110000		0xF0
*  *		10010000		0x90
*  *		10010000		0x90
*  *		10010000		0x90
****		11110000		0xF0

*/
static array<uint8_t, 80> chip8_fontset =
{
	0xF0, 0x90, 0x90, 0x90, 0xF0, //0
	0x20, 0x60, 0x20, 0x20, 0x70, //1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, //2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, //3
	0x90, 0x90, 0xF0, 0x10, 0x10, //4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, //5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, //6
	0xF0, 0x10, 0x20, 0x40, 0x40, //7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, //8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, //9
	0xF0, 0x90, 0xF0, 0x90, 0x90, //A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, //B
	0xF0, 0x80, 0x80, 0x80, 0xF0, //C
	0xE0, 0x90, 0x90, 0x90, 0xE0, //D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, //E
	0xF0, 0x80, 0xF0, 0x80, 0x80  //F
};

chip8::chip8()
{
}


chip8::~chip8()
{
}

void chip8::emulateCycle()
{
	// Fetch opcode, opcode is two bytes
	m_opcode = m_memory[m_program_counter] << 8 | m_memory[m_program_counter + 1]; 

	uint16_t const NNN = m_opcode & 0x0FFF;
	uint8_t const NN = m_opcode & 0x00FF;
	uint8_t const N = m_opcode & 0x000F;
	uint8_t const X = (m_opcode & 0x0F00) >> 8;
	uint8_t const Y = (m_opcode & 0x00F0) >> 4;

	m_program_counter += 2;

	switch (m_opcode & 0xF000)
	{
	// ANNN
	case 0x0000:

		switch (NN)
		{
		
		case 0x00E0: //Clears the screen.
			gfx = {};
			drawFlag = true;
			
			break;

		
		case 0x00EE: // Returns from subroutine			

			// Put the stored return address from the stack back into the program counter		
			m_program_counter = m_stack.top();
			m_stack.pop();			

		default:
			std::cout << "Unknown opcode [0x0000]: 0x" << m_opcode << "\n";
			break;
		}
		break;
	
	case 0x1000: // Jumps to address NNN
		m_program_counter = NNN;
		break;

	case 0x2000: // Calls subroutine at NNN.
		m_stack.push(m_program_counter);
		m_program_counter = NNN;
		break;

	case 0x3000: // Skips the next instruction if VX equals NN. (Usually the next instruction is a jump to skip a code block)
		if (m_V[X] == NN)
		{
			m_program_counter += 2;
		}			
		break;

	case 0x4000: // Skips the next instruction if VX doesn't equal NN. (Usually the next instruction is a jump to skip a code block)
		if (m_V[X] != NN)
		{
			m_program_counter += 2;
		}			
		break;

	case 0x5000: // Skips the next instruction if VX equals VY. (Usually the next instruction is a jump to skip a code block)
		if (m_V[X] == m_V[Y])
		{
			m_program_counter += 2;
		}
		break;

	case 0x6000: // Sets VX to NN.
		m_V[X] = NN;		
		break;

	case 0x7000: // Adds NN to VX. (Carry flag is not changed)
		m_V[X] += NN;		
		break;

	case 0x8000: 
		switch (N)
		{
		case 0x0000: // Sets VX to the value of VY.
			m_V[X] = m_V[Y];	
			break;

		case 0x0001: // Sets VX to VX or VY. (Bitwise OR operation)
			m_V[X] |= m_V[Y];
			break;

		case 0x0002: // Sets VX to VX and VY. (Bitwise AND operation)
			
			break;

		case 0x0003: // Sets VX to VX xor VY.
			
			break;

		case 0x0004: // Adds VY to VX. VF is set to 1 when there's a carry, and to 0 when there isn't.
			
			break;

		case 0x0005: // VY is subtracted from VX. VF is set to 0 when there's a borrow, and 1 when there isn't.
			
			break;

		case 0x0006: // Stores the least significant bit of VX in VF and then shifts VX to the right by 1.
			
			break;

		case 0x0007: // Sets VX to VY minus VX. VF is set to 0 when there's a borrow, and 1 when there isn't.
			
			break;

		case 0x000E: // 	Stores the most significant bit of VX in VF and then shifts VX to the left by 1.
			
			break;
		default:
			std::cout << "Unknown opcode [0x8000]: 0x" << m_opcode << "\n";
			break;
		}

		break;
	default:
		break;
	}

}

void chip8::debugRender()
{
}

void chip8::loadFromRom(string const fileName)
{
	
}

void chip8::init()
{
	// program counter starts at memory location 512 (0x200) 
	m_program_counter = memory_start;
	m_opcode = 0;
	m_index_register = 0;
	m_delay_timer = 0;
	m_sound_timer = 0;

	gfx = {};
	key = {};
	m_V = {};
	m_memory = {};
	
	while (!m_stack.empty())
	{
		m_stack.pop();
	}
	
	// load fontset to memory
	for (int i = 0; i < sizeof(chip8_fontset); ++i)
	{
		m_memory[i] = chip8_fontset[i];
	}

	drawFlag = true;
}
