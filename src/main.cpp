#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

#include "Processor.h"


Accumulator *accumulator;
ALU *alu;
Databus *databus;
Flag *flag;
IO_RF *io;
MainMemory *mainMemory;
MemoryAddress *memoryAddress;
Microinstruction *microinstruction;
Operand *operand;
ProgramCounter *programCounter;
RegisterArray *registerArray;
StackPointer *stackPointer;

void init(std::string path) {
	accumulator = new Accumulator();
	alu = new ALU();
	databus = new Databus();
	flag = new Flag();
	io = new IO_RF();
	mainMemory = new MainMemory(path);
	memoryAddress = new MemoryAddress();
	microinstruction = new Microinstruction();
	operand = new Operand();
	programCounter = new ProgramCounter();
	registerArray = new RegisterArray();
	stackPointer = new StackPointer();
}

void cleanup () {
	delete accumulator;
	delete alu;
	delete databus;
	delete flag;
	delete io;
	delete mainMemory;
	delete memoryAddress;
	delete microinstruction;
	delete operand;
	delete programCounter;
	delete registerArray;
	delete stackPointer;
}

int main(int argc, char const *argv[]) {
	init("./Assembler/assemble.out");

	// registerArray->clockPulse();
	// databus->setContent(1);
	// microinstruction->LIO = true;
	// io->processSignal();
	// io->clockPulse();
	// std::cout <<io->SFL<<std::endl;
	// std::cout <<flag->getFlag()<<std::endl;
	// flag->setNZ();
	// databus->resetBusy();
	// databus->setContent(2);
	// microinstruction->LIO = true;
	// io->processSignal();
	// io->clockPulse();
	// std::cout <<io->SFL<<std::endl;
	// std::cout <<flag->getFlag()<<std::endl;

	// operand->setContent( 0 );
	// databus->setContent( 127 );
	// operand->clockPulse();
	// microinstruction->SAF = 1;
	// std::cout <<alu->getContent()<<std::endl;
	// std::cout <<flag->getC()<<std::endl;
	// std::cout <<flag->getS()<<std::endl;
	// std::cout <<flag->getNS()<<std::endl;


	//	flag->setS();
	//	std::cout <<flag->getS();
	//	flag->resetS();
	//	std::cout <<flag->getS();
	//	std::cout <<flag->getU();

	//	databus->setContent( 10 );
	//	operand->setContent ( 20 );
	//	operand->clockPulse();
	//	microinstruction->SAF = 1;
	//	std::cout <<(microinstruction->SAF & 15)<<std::endl;
	//	std::cout <<alu->getContent()<<std::endl;

	cleanup();
	return 0;
}
