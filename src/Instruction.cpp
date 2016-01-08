#ifndef _INSTRUCTION_CPP
#define _INSTRUCTION_CPP

#include "include/Instruction.h"
#include "include/Processor.h"

Instruction::Instruction () {

}

Instruction::~Instruction () {

}

void Instruction::processSignalRisingEdge(){

}

void Instruction::processSignalFallingEdge(){
	if (microinstruction->LIR){
		std::cout << "LIR\t";
		this->setContent(databus->getContent());
	}
}

#endif
