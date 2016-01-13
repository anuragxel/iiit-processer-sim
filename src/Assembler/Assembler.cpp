#ifndef _ASSEMBLER_CPP
#define _ASSEMBLER_CPP

#include "Assembler.h"

bool isALabel(std::string word) {
	return (word.find(":") != std::string::npos);
}

bool isAnInstruction(std::string word) {
	return (opCode.find(word) != opCode.end());
}

bool isARegister(std::string word) {
	return (registers.find(word) != registers.end());
}

bool islabelPresent(std::string word) {
	return (lookupTable.find(word) != lookupTable.end());
}

int typeOfInstruction(int currCode) {
	if( currCode == 0x02 or currCode == 0x03 or currCode == 0x04 or currCode == 0x05 or
	    currCode == 0x06 or currCode == 0x07 )
		return IMMEINST;
	else if( currCode == 0x10 or currCode == 0x20 or currCode == 0x30 or currCode == 0x40 or
		 currCode == 0x50 or currCode == 0x60 or currCode == 0x70 or currCode == 0x80 or
		 currCode == 0xA0 or currCode == 0xB0 or currCode == 0xC0 or currCode == 0xD0 )
		return REGINST;
	else if( currCode == 0xE0 or currCode == 0xE1 or currCode == 0xE2 or currCode == 0xE3 or
		 currCode == 0xE4 or currCode == 0xE5 or currCode == 0xE6 or currCode == 0xE7 )
		return JMPDINST;
	else if( currCode == 0x90 )
		return MOVIINST;
	else if( currCode == 0xF0 or currCode == 0xF1 or currCode == 0xF2 or currCode == 0xF3 or
		 currCode == 0xF4 or currCode == 0xF5 or currCode == 0xF6 or currCode == 0xF7 )
		return CDINST;
	else
		return 0;
}

void initialize() {
	memory.fill(0); // I love C++ oneliners;
	nextInstructionAddr = 0;
}

void printError(std::string error) {
	std::cerr << error << nextInstructionAddr << std::endl;
}

void printTable() {
	std::cout << "symbolTable = { " << std::endl;
	for( auto elem : lookupTable ) {
		std::cout << "\t" << elem.first << " : " << elem.second << std::endl; 
	}
	std::cout << "} " << std::endl; 
}

/* A Two pass Assembler for the iiit-processor assembly language */
int assembleCode(std::string path,std::string outpath) {
	std::string word;
	std::ifstream infile;
	std::ofstream outfile;
	int currCode = 0;
	int regCode = 0;
	infile.open(path, std::ios::in);

	// first pass through the assembly code
	while(infile >> word) {
		if ( isAnInstruction(word) ) {
			// finding the opcode of the current instruction.
			currCode = opCode[word];
			if ( typeOfInstruction(currCode) == IMMEINST ) { //opcode xx
				infile >> word; // xx
				memory[nextInstructionAddr++] = currCode; // opcode
				if( stoi(word) > 256 ) {
					printError("Constant is too big. Use Only 8 Bit Constants. Line: ");
					return 1;
				}
				memory[nextInstructionAddr++] = stoi(word); // xx
			}
			else if ( typeOfInstruction(currCode) == REGINST ) { // opcode
				infile >> word; // <R>
				if( not isARegister(word) ) {
					printError("Improper Register. (r[0-11],sp,pc,ar,or) Line: ");
					return 1;
				}
				regCode = registers[word];
				currCode = currCode | regCode; // partial op code is completed with the register code
				memory[nextInstructionAddr++] = currCode;
			}
			else if ( typeOfInstruction(currCode) == JMPDINST ) {
				infile >> word;
				memory[nextInstructionAddr++] = currCode;
				// at the position for the address for the label we just leave -1.
				memory[nextInstructionAddr++] = -1;
			}
			else if( typeOfInstruction(currCode) == MOVIINST ) {
				infile >> word; // <R>
				if( not isARegister(word) ) {
					printError("Improper Register. (r[0-11],sp,pc,ar,or) Line: ");
					return 1;
				}
				regCode = registers[word];
				currCode = currCode | regCode; // partial op code is completed with the register code
				memory[nextInstructionAddr++] = currCode;
				infile >> word; // xx
				if( stoi(word) > 256 ) {
					printError("Constant is too big. Use Only 8 Bit Constants. Line: ");
					return 1;
				}
				memory[nextInstructionAddr++] = stoi(word);
			}
			else if ( typeOfInstruction(currCode) == CDINST ) {
				infile >> word;
				memory[nextInstructionAddr++] = currCode;
				// at the position for the address for the label we just leave -1.
				memory[nextInstructionAddr++] = -1;
			}
			else {
				memory[nextInstructionAddr++] = currCode;
			}
		}
		else if ( isALabel(word) ) {
			// building up the lookup table with the labels defined in the code.
			word = word.erase(word.size() - 1);
			if( islabelPresent(word) ) {
				std::string err = "Duplicate Label '" + word + "'. Lines: " + std::to_string(lookupTable[word]) + ", "; 
				printError(err);
				printTable();
				return 1;
			}
			lookupTable[word] = nextInstructionAddr;
		}
		else {
		}
	}

	infile.clear();
	infile.seekg(0, std::ios::beg);
	nextInstructionAddr = 0;

	//second pass through the assembly code.
	while(infile >> word) {
		if ( isAnInstruction(word) ) {
			currCode = opCode[word];
			if ( typeOfInstruction(currCode) == IMMEINST ) {
				infile >> word;
				nextInstructionAddr += 2;
			}
			else if ( typeOfInstruction(currCode) == REGINST ) {
				infile >> word;
				nextInstructionAddr++;
			}
			else if ( typeOfInstruction(currCode) == JMPDINST ) {
				infile >> word;
				nextInstructionAddr++;
				if( not islabelPresent(word) ) {
					std::string err = "Label '" + word + "' Not Defined Line: ";
					printError(err);
					printTable();
					return 1;
				}
				memory[nextInstructionAddr++] = lookupTable[word];
			}
			else if( typeOfInstruction(currCode) == MOVIINST ) {
				infile >> word; // <R>
				infile >> word; // xx
				nextInstructionAddr += 2;
			}
			else if ( typeOfInstruction(currCode) == CDINST ) {
				infile >> word;
				nextInstructionAddr++;
				if( not islabelPresent(word) ) {
					std::string err = "Label '" + word + "' Not Defined Line: ";
					printError(err);
					printTable();
					return 1;
				}
				memory[nextInstructionAddr++] = lookupTable[word];
			}
			else {
			}
		}
	}
	infile.close();
	outfile.open(outpath, std::ios::trunc | std::ios::binary);
	outfile.write((char *) &memory, sizeof(memory)); // I love C++ oneliners;
	outfile.close(); // Many OS makes lazy buffer flush. Be sure to clean before exit.
	printTable();
	return 0;
}


int main(const int argc, char **argv) {
	initialize();
	int rv = 1;
	if(argc == 2) {
		rv  = assembleCode(argv[1], "assemble.out");
	}
	else if(argc == 3) {
		rv = assembleCode(argv[1], argv[2]);
	}
	else {
		std::cerr << "USAGE : assemble infile [outfile]" << std::endl;
	}
	if(rv == 0) {
		std::cout << "Assembled Succesfully!" << std::endl;
	}
	return 0;
}

#endif
