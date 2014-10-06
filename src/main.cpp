#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

#include "Processor.h"

Accumulator *accumulator = new Accumulator();
ALU *alu = new ALU();
Databus *databus = new Databus();
Flag *flag = new Flag();
IO_RF *io = new IO_RF();
MemoryAddress *memoryAddress = new MemoryAddress();
Microinstruction *microinstruction = new Microinstruction();
Operand *operand = new Operand();
ProgramCounter *programCounter = new ProgramCounter();
RegisterArray *registerArray = new RegisterArray();
StackPointer *stackPointer = new StackPointer();

int main(int argc, char const *argv[]) {

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

	delete accumulator;
	delete alu;
	delete databus;
	delete flag;
	delete io;
	delete memoryAddress;
	delete microinstruction;
	delete operand;
	delete programCounter;
	delete registerArray;
	delete stackPointer;
	return 0;
}
