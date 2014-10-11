#ifndef _OPERAND_CPP
#define _OPERAND_CPP

#include "Operand.h"
#include "Processor.h"

Operand::Operand () {

}

Operand::~Operand () {

}

void Operand::processSignal () {
	if (microinstruction->EOR)
		databus->setContent(this->getContent());
	if (microinstruction->ROR)
		this->setContent(0);
	if (microinstruction->LOR)
		this->setContent(databus->getContent());
}

#endif
