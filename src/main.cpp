#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

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

void printState() {
	std::cout <<"ALU  : "<<alu->getContent();
	std::cout <<"\tACC  : "<<accumulator->getContent();
	std::cout <<"\tDTBS : "<<databus->getContent();
	std::cout <<"\tDEC  : " <<decoder->getContent();
	std::cout <<"\tPC   : "<<programCounter->getContent()<<std::endl;

	std::cout <<"MEM  : "<<mainMemory->getContent();
	std::cout <<"\tMADD : "<<memoryAddress->getContent();
	std::cout <<"\tIO   : "<<io->getContent();
	std::cout <<"\tIR   : "<<instruction->getContent();
	std::cout <<"\tMS   : "<<microprogramSequencer->getContent() << std::endl;

	std::cout <<flag->toString();
	std::cout <<registerArray->toString()<<std::endl;

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
		flag->processSignalRisingEdge();

		// TODO: KNOW WHY??!!
		//memoryAddress->updateImmediate();

		mainMemory->processSignalRisingEdge();

		operand->processSignalRisingEdge(microinstruction, databus);

		programCounter->processSignalRisingEdge(microinstruction, databus);
		registerArray->processSignalRisingEdge();
		stackPointer->processSignalRisingEdge(microinstruction, databus);

		accumulator->processSignalFallingEdge(microinstruction, alu);

		flag->processSignalFallingEdge();
		instruction->processSignalFallingEdge(microinstruction, databus);
		io->processSignalFallingEdge(microinstruction, databus);

		memoryAddress->processSignalFallingEdge(microinstruction, databus);
		//memoryAddress->updateImmediate();

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
	// The processor. :P
	for(int i = 0 ; instruction->getContent() != 0x01 ; i++) {

		std::cout << std::endl << "Clock Cycle : " << i <<std::endl;
		if(verbose) {
			printState();
		}
		executeClockCycle();
		std::cout << std::endl;
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
