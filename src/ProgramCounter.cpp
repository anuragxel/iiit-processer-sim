#ifndef _PROGRAMCOUNTER_CPP
#define _PROGRAMCOUNTER_CPP

#include "include/ProgramCounter.h"
#include "include/Processor.h"

ProgramCounter::ProgramCounter () {

}

ProgramCounter::~ProgramCounter () {

}

void ProgramCounter::processSignalRisingEdge(){
	if (microinstruction->EPC){
		std::cout << "EPC\t";
		databus->setContent(this->getContent());
	}
}

void ProgramCounter::processSignalFallingEdge(){
	if (microinstruction->IPC) {
		std::cout << "IPC\t";
		this->increment();
	}
	if (microinstruction->LPC) {
		std::cout << "LPC\t";
		this->setContent(databus->getContent());
	}
}

#endif
