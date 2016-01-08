/*
 * This file is part of Std-Arch-Sim.
 *
 * Std-Arch-Sim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Std-Arch-Sim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Std-Arch-Sim.  If not, see <http://www.gnu.org/licenses/>.
 */
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

void executeClockCycle() {

		databus->resetBusy();

		accumulator->processSignalRisingEdge();
		flag->processSignalRisingEdge();
		instruction->processSignalRisingEdge();
		io->processSignalRisingEdge();

		memoryAddress->processSignalRisingEdge();
		memoryAddress->updateImmediate();

		mainMemory->processSignalRisingEdge();

		//microprogramSequencer->processSignalRisingEdge();
		operand->processSignalRisingEdge();

		programCounter->processSignalRisingEdge();
		registerArray->processSignalRisingEdge();
		stackPointer->processSignalRisingEdge();

		accumulator->processSignalFallingEdge();

		flag->processSignalFallingEdge();
		instruction->processSignalFallingEdge();
		io->processSignalFallingEdge();

		memoryAddress->processSignalFallingEdge();
		memoryAddress->updateImmediate();

		mainMemory->processSignalFallingEdge();

		//microprogramSequencer->processSignalFallingEdge();
		operand->processSignalFallingEdge();

		programCounter->processSignalFallingEdge();
		registerArray->processSignalFallingEdge();
		stackPointer->processSignalFallingEdge();

		accumulator->clockPulse();
		flag->clockPulse();
		instruction->clockPulse();
		io->clockPulse();
		memoryAddress->clockPulse();
		microprogramSequencer->clockPulse();
		operand->clockPulse();
		programCounter->clockPulse();
		registerArray->clockPulse();
		stackPointer->clockPulse();

		// why twice ?
		microprogramSequencer->processSignalRisingEdge();
		microprogramSequencer->processSignalFallingEdge();
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
	bool verbose = true;

	// The processor. :P
	for(int i = 0 ; instruction->getContent() != 0x01 ; i++) {

		std::cout << std::endl <<"Clock Cycle : " << i <<std::endl;
		if(verbose) {
			printState();
		}
		executeClockCycle();
		std::cout << std::endl;

	}

	std::cout << "\n\nExecution Over" << std::endl;
	printState();
	printMemory();

	cleanup();
	return 0;
}
