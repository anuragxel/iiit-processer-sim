#ifndef _ASSEMBLER_CPP
#define _ASSEMBLER_CPP

#include "Assembler.h"

using namespace std;

struct tableEntry
{
	std::string symbol;
	int location;
};

int nextInstructionAddr;
int nextSymbolTableIdx;
int flags[MEMSIZE];
int memory[MEMSIZE];

std::map <std::string,int> lookupTable;

std::map <std::string,int> registers = 
{
	{"r0", 0x00 },
	{"r1", 0x01 },
	{"r2", 0x02 },
	{"r3", 0x03 },
	{"r4", 0x04 },
	{"r5", 0x05 },
	{"r6", 0x06 },
	{"r7", 0x07 },
	{"r8", 0x08 },
	{"r9", 0x09 },
	{"r10", 0x0A },
	{"r11", 0x0B },
	{"pc", 0x0C },
	{"sp", 0x0D },
	{"ar", 0x0E },
	{"or", 0x0F },
};

std::map <std::string,int> opCode = 
{
	{ "nop", 0x00  },
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

bool isAnInstruction(std::string word)
{
	return (opCode.find(word) != opCode.end());
}
int typeOfInstruction(int currCode) { 
	switch(currCode) 
	{
		case 0x03: // immediate
			return IMMEINST;
			break;
		case 0x04: // immediate
			return IMMEINST;
			break;
		case 0x05: // immediate
			return IMMEINST;
			break;
		case 0x06: // immediate
			return IMMEINST;
			break;
		case 0x07: // immediate
			return IMMEINST;
			break;	
		case 0x10: //adding register to op code
			return REGINST;
			break;
		case 0x20: //adding register to op code
			return REGINST;
			break;
		case 0x30: //adding register to op code
			return REGINST;
			break;
		case 0x40: //adding register to op code
			return REGINST;
			break;
		case 0x50: //adding register to op code
			return REGINST;
			break;
		case 0x60: //adding register to op code
			return REGINST;
			break;
		case 0x70: //adding register to op code
			return REGINST;
			break;
		case 0xA0: //adding register to op code
			return REGINST;
			break;
		case 0xB0: //adding register to op code
			return REGINST;
			break;
		case 0xC0: //adding register to op code
			return REGINST;
			break;
		case 0xD0: //adding register to op code
			return REGINST;
			break;
		case 0xE0: // jumpd type
			return JMPDINST;
			break;
		case 0xE1: // jumpd type
			return JMPDINST;
			break;
		case 0xE2: // jumpd type
			return JMPDINST;
			break;
		case 0xE3: // jumpd type
			return JMPDINST;
			break;
		case 0xE4: // jumpd type
			return JMPDINST;
			break;
		case 0xE5: // jumpd type
			return JMPDINST;
			break;
		case 0xE6: // jumpd type
			return JMPDINST;
			break;
		case 0xE7: // jumpd type
			return JMPDINST;
			break;
		case 0x90: //movi
			return MOVIINST;
			break;
		case 0xF0: // cd type
			return CDINST;
			break;
		case 0xF1: // cd type
			return CDINST;
			break;
		case 0xF2: // cd type
			return CDINST;
			break;
		case 0xF3: // cd type
			return CDINST;
			break;
		case 0xF4: // cd type
			return CDINST;
			break;
		case 0xF5: // cd type
			return CDINST;
			break;
		case 0xF6: // cd type
			return CDINST;
			break;
		case 0xF7: // cd type
			return CDINST;
			break;
		default:
			return 0;
			break;
	}
} 
void initialize()
{
	for(int i = 0;i<MEMSIZE;i++)
	{
		memory[i] = 0;
		flags[i] = -1;
	}
	nextInstructionAddr = 0;
	nextSymbolTableIdx = 0;
}

void assembleCode(std::string path,std::string outpath)
{
	std::string word,word1;
	fstream file;
	fstream outfile;
	int currCode = 0;
	int regCode = 0;
	file.open(path, ios::in);
	
	if( outpath != "stdout" )
		outfile.open(outpath, ios::out);

	// first pass through the code
	while(file >> word) 
	{ 
		if ( isAnInstruction(word) )
		{
			currCode = opCode[word];
			if ( typeOfInstruction(currCode) == IMMEINST ) {
				file >> word;
				cout << hex << currCode;
				cout << "			" << word;
			}
			else if ( typeOfInstruction(currCode) == REGINST ) {
				file >> word;
				regCode = registers[word];
				currCode = currCode + regCode;
				cout << hex << currCode;
			}
			else if ( typeOfInstruction(currCode) == JMPDINST ) {
				file >> word;
				cout << hex << currCode;
				cout << "		" << word;
			}
			else if( typeOfInstruction(currCode) == MOVIINST ) {
				file >> word; // <R>
				regCode = registers[word];
				currCode = currCode + regCode;
				file >> word; // xx
				cout << hex << currCode;
				cout << "		" << word;
			}
			else if ( typeOfInstruction(currCode) == CDINST ) {
				file >> word;
				cout << hex << currCode;
				cout << "		" << word;	
			}
			else {
				cout << hex << currCode;
			}
			cout << endl;
		}
		else {
			cout << "FUCK YOU !!" << endl;
			break;
		}
	}
}

int main(const int argc, char **argv)
{
	initialize();
	if(argc == 2)
		assembleCode(argv[1],"stdout");
	else if(argc == 4)
		assembleCode(argv[2],argv[3]);
	else
		cout << "USAGE : assemble -o infile outfile" << endl;
}

#endif