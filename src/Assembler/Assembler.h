#ifndef _ASSEMBLER_H
#define _ASSEMBLER_H

#define MEMSIZE 256

// Instructions can be divided into these classes and one more for parsing.
#define IMMEINST 1
#define REGINST 2
#define JMPDINST 3
#define MOVIINST 4
#define CDINST 5

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <array>

std::array <char, MEMSIZE> memory;
int nextInstructionAddr;
std::map <std::string, int> lookupTable;

std::map <std::string, int> registers =
{
	// general registers
	{ "r0", 0x00 },
	{ "r1", 0x01 },
	{ "r2", 0x02 },
	{ "r3", 0x03 },
	{ "r4", 0x04 },
	{ "r5", 0x05 },
	{ "r6", 0x06 },
	{ "r7", 0x07 },
	{ "r8", 0x08 },
	{ "r9", 0x09 },
	{ "r10", 0x0A },
	{ "r11", 0x0B },

	// special registers
	{ "pc", 0x0C },
	{ "sp", 0x0D },
	{ "ar", 0x0E },
	{ "or", 0x0F },
};

std::map <std::string, int> opCode =
{
	// no operation
	{ "nop", 0x00  },

	// stop processor operation.
	{ "stop", 0x01 },

	// if of the format adi xx
	// [AR] <-- [AR] {op} xx
	{ "adi", 0x02 },
	{ "subi", 0x03 },
	{ "xri", 0x04 },
	{ "ani", 0x05 },
	{ "ori", 0x06 },
	{ "cmi", 0x07 },

	// PC <- [[SP]], [SP] <- [SP] + 1 if <FL> = 1
	{ "retu", 0x08 },
	{ "retz", 0x09 },
	{ "retnz", 0x0A },
	{ "retc", 0x0B },
	{ "retnc", 0x0C },
	{ "retp", 0x0D },
	{ "retm", 0x0E },
	{ "retop", 0x0F },

	// is of the format add <R>
	// we actually do add 00 - 0F to the opCode for the register number
	// [AR] <- [AR] {op} <R>
	{ "add", 0x10 },
	{ "sub", 0x20 },
	{ "xor", 0x30 },
	{ "and", 0x40 },
	{ "or", 0x50  },

	// cmp <R>
	// [AR] - <R> (Only flags)
	// we actually do add 00 - 0F to the opCode for the register number
	{ "cmp", 0x60  },

	// movs <R>
	// [OR] <- [<R>] , [AR] <- [<R>]
	// we actually do add 00 - 0F to the opCode for the register number
	{ "movs", 0x70 },

	// movd <R>
	// [<R>] <- [AR]
	// we actually do add 00 - 0F to the opCode for the register number
	{ "movd", 0x80 },

	// is of the format movi <R> xx,
	// we actually do add 00 - 0F to the opCode for the register number
	{ "movi" , 0x90 },

	// we actually do add 00 - 0F to the opCode for the register number
	{ "store", 0xA0 },
	{ "load", 0xB0 },
	{ "push", 0xC0 },
	{ "pop", 0xD0 },

	// is of the format jmpd<FL> label
	// [PC] <- label if <FL> = 1
	// label is an memory address pointing to a code point
	{ "jmpdu", 0xE0 },
	{ "jmpdz", 0xE1 },
	{ "jmpdnz", 0xE2 },
	{ "jmpdc", 0xE3 },
	{ "jmpdnc", 0xE4 },
	{ "jmpdp", 0xE5 },
	{ "jmpdm", 0xE6 },
	{ "jmpdop", 0xE7 },

	// is of the format jmpr<FL>
	// [PC] ← [AR] if <FL> = 1
	{ "jmpru", 0xE8 },
	{ "jmprz", 0xE9 },
	{ "jmprnz", 0xEA },
	{ "jmprc", 0xEB },
	{ "jmprnc", 0xEC },
	{ "jmprp", 0xED },
	{ "jmprm", 0xEE },
	{ "jmprop", 0xEF },

	// if of the format cd<FL> xx
	//[SP] ← [SP] – 1, [[SP]] ← [PC], [PC] ← xx if <FL> = 1
	{ "cdu", 0xF0 },
	{ "cdz", 0xF1 },
	{ "cdnz", 0xF2 },
	{ "cdc", 0xF3 },
	{ "cdnc", 0xF4 },
	{ "cdp", 0xF5 },
	{ "cdm", 0xF6 },
	{ "cdop", 0xF7 },

	// if of the format cr<FL>
	// [SP] ← [SP] – 1, [[SP]] ← PC], [PC] ← [AR] if <FL> = 1
	{ "cru", 0xF8 },
	{ "crz", 0xF9 },
	{ "crnz", 0xFA },
	{ "crc", 0xFB },
	{ "crnc", 0xFC },
	{ "crp", 0xFD },
	{ "crm", 0xFE },
	{ "crop", 0xFF },

};

void initialize();
void assembleCode(std::string, std::string);
int typeOfInstruction(int);
bool isALabel(std::string);
bool isAnInstruction(std::string);
bool isARegister(std::string word);
bool islabelPresent(std::string word);

#endif
