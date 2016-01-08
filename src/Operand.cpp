#ifndef _OPERAND_CPP
#define _OPERAND_CPP

#include "include/Operand.h"
#include "include/Processor.h"

Operand::Operand () {

}

Operand::~Operand () {

}

void Operand::processSignalRisingEdge(){
	if (microinstruction->EOR){
		std::cout << "EOR\t";
		databus->setContent(this->getContent());
	}
}

void Operand::processSignalFallingEdge(){
	if (microinstruction->ROR){
		std::cout << "ROR\t";
		this->setContent(0);
	}
	if (microinstruction->LOR) {
		std::cout << "LOR\t";
		this->setContent(databus->getContent());
	}
}

#endif
