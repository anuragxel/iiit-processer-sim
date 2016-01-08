#ifndef _MEMORYADDRESS_CPP
#define _MEMORYADDRESS_CPP

#include "include/MemoryAddress.h"
#include "include/Processor.h"

MemoryAddress::MemoryAddress () {
}

MemoryAddress::~MemoryAddress () {

}

void MemoryAddress::processSignalRisingEdge(){

}

void MemoryAddress::processSignalFallingEdge(){
	if (microinstruction->LMR){
		std::cout << "LMR\t";
		this->setContent(databus->getContent());
	}
}

void MemoryAddress::updateImmediate () {
	Register::clockPulse();
}

#endif
