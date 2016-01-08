#ifndef _ACCUMULATOR_CPP
#define _ACCUMULATOR_CPP

#include "include/Accumulator.h"
#include "include/Processor.h"

Accumulator::Accumulator () {

}

Accumulator::~Accumulator () {

}

void Accumulator::processSignalRisingEdge(){
	if(microinstruction->EAR) {
		std::cout << "EAR\t";
		databus->setContent(this->getContent());
	}
}

void Accumulator::processSignalFallingEdge(){
	if (microinstruction->RAR){
		std::cout << "RAR\t";
		this->setContent(0);
	}
	if (microinstruction->LAR){
		std::cout << "LAR\t";
		this->setContent(alu->getContent());
	}
}

#endif
