#ifndef _INSTRUCTION_CPP
#define _INSTRUCTION_CPP

#include "Instruction.h"
#include "Processor.h"

Instruction::Instruction () {

}

Instruction::~Instruction () {

}

void Instruction::processSignal () {
	if (microinstruction->LAR)
		this->setContent(databus->getContent());
}

#endif
