#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

#include <bitset>

#include "include/Processor.h"

Accumulator *accumulator;
ALU *alu;
Databus *databus;
Decoder *decoder;
Flag *flag;
Instruction *instruction;
IO_RF *io;
MainMemory *mainMemory;
MemoryAddress *memoryAddress;
Microinstruction *microinstruction;
MicroprogramSequencer *microprogramSequencer;
Operand *operand;
ProgramCounter *programCounter;
RegisterArray *registerArray;
ROM *rom;
StackPointer *stackPointer;

void init(std::string path) {
	accumulator = new Accumulator();
	alu = new ALU();
	databus = new Databus();
	decoder = new Decoder();
	flag = new Flag();
	instruction = new Instruction();
	io = new IO_RF();
	mainMemory = new MainMemory(path);
	memoryAddress = new MemoryAddress();
	microinstruction = new Microinstruction();
	microprogramSequencer = new MicroprogramSequencer();
	operand = new Operand();
	programCounter = new ProgramCounter();
	registerArray = new RegisterArray();
	rom = new ROM();
	stackPointer = new StackPointer();
	microinstruction->resetContent();
}

void cleanup () {
	delete accumulator;
	delete alu;
	delete databus;
	delete decoder;
	delete flag;
	delete instruction;
	delete io;
	delete mainMemory;
	delete memoryAddress;
	delete microinstruction;
	delete microprogramSequencer;
	delete operand;
	delete programCounter;
	delete registerArray;
	delete rom;
	delete stackPointer;
}

void printRegisters() {
	std::string top = " PC\tSP\tACC\tOR\tR0\tR1\tR2\tR3\tR4\tR5\tR6\tR7\tR8\tR9\tR10\tR11";
	std::string reg_string = " " + programCounter->toString() + "\t";
	reg_string += stackPointer->toString() + "\t";
	reg_string += accumulator->toString() + "\t";
	reg_string += operand->toString() + "\t";
	reg_string += registerArray->toString();
	std::cout << top << std::endl;
	std::cout << reg_string << std::endl;
}

std::string string_maker(int val) {
		if(val == 0) {
			return " ";
		}
		return std::to_string(val);
}

void printMisc() {
	std::string top = " ALU\tDTBS\tDEC\tMEM\tMADD\tIO\tIR\tMS";
	std::bitset<4> alu_bits(alu->getContent());
	std::string reg_string = " 0b" + alu_bits.to_string<char, std::string::traits_type, std::string::allocator_type>() + "\t";
	reg_string += string_maker(databus->getContent()) + "\t";
	reg_string += string_maker(decoder->getContent()) + "\t";
	reg_string += string_maker(mainMemory->getContent()) + "\t";
	reg_string += memoryAddress->toString() + "\t";
	reg_string += io->toString() + "\t";
	reg_string += instruction->toString() + "\t";
	reg_string += microprogramSequencer->toString() + "\t";
	std::cout << top << std::endl;
	std::cout << reg_string << std::endl;
}

void printState() {
	std::string outline = "________________________________________________________________";
	std::cout << outline << outline << std::endl;
	printRegisters();
	std::cout << outline << outline << std::endl;
	printMisc();
	std::cout << outline << outline << std::endl;
	std::cout << flag->toString();
	std::cout <<std::endl;
}

void printMemory() {
	std::cout << "Memory : " << std::endl;
	std::cout << mainMemory->toString() << std::endl;
}

void editMemory() {
	std::cout << "Edit Memory by entering values in the format 'index value' line by line." << std::endl;
	std::cout << "The index and values should be in Base 10 and in the range 0-255" << std::endl;
	std::cout << "Enter -1 : -1 to indicate that you are done." << std::endl;
	int index, val;
	std::string line;
	while(true) {
		std::cin >> index >> val;
		if(index == -1 and val == -1) {
			break;
		}
		if (index < 0 || index > 255) {
			std::cout << "Invalid Index" << std::endl;
			continue;
		}
		mainMemory->manualEdit(index, val);
	}
}

void executeClockCycle() {

		databus->resetBusy();

		accumulator->processSignalRisingEdge(microinstruction, databus);
		mainMemory->processSignalRisingEdge();
		operand->processSignalRisingEdge(microinstruction, databus);
		programCounter->processSignalRisingEdge(microinstruction, databus);
		registerArray->processSignalRisingEdge();
		stackPointer->processSignalRisingEdge(microinstruction, databus);

		accumulator->processSignalFallingEdge(microinstruction, alu);
		instruction->processSignalFallingEdge(microinstruction, databus);
		io->processSignalFallingEdge(microinstruction, databus);
		memoryAddress->processSignalFallingEdge(microinstruction, databus);
		mainMemory->processSignalFallingEdge();
		operand->processSignalFallingEdge(microinstruction, databus);
		programCounter->processSignalFallingEdge(microinstruction, databus);
		registerArray->processSignalFallingEdge();
		stackPointer->processSignalFallingEdge(microinstruction, databus);

		accumulator->clockPulse();
		flag->clockPulse();
		instruction->clockPulse();
		io->clockPulse();
		memoryAddress->clockPulse();
		microprogramSequencer->clockPulse(microinstruction);
		operand->clockPulse();
		programCounter->clockPulse();
		registerArray->clockPulse();
		stackPointer->clockPulse();

		// why twice ?
		microprogramSequencer->processSignalFallingEdge(microinstruction, io, flag, decoder);
	  microprogramSequencer->updateImmediate();

		rom->setMicroinstruction();

}

int main(int argc, char const **argv) {
	if(argc == 2) {
		init(argv[1]);
	}
	else {
		init("./Assembler/assemble.out");
	}

	printMemory();
	editMemory();
	printMemory();
	bool verbose = true;
	int val;
	std::string outline = "################################################################";

	// The processor. :P
	for(int i = 0 ; instruction->getContent() != 0x01 ; i++) {

		std::cout << outline << outline << std::endl;
		std::cout << std::endl << "Clock Cycle : " << i <<std::endl;
		executeClockCycle();
		std::cout << std::endl;
		if(verbose) {
			printState();
		}
		std::cout << outline << outline << std::endl;
		std::cin >> val;
		if(val == 0) {
				break;
		}
	}

	std::cout << "\n\nExecution Over" << std::endl;
	printState();
	printMemory();

	cleanup();
	return 0;
}
