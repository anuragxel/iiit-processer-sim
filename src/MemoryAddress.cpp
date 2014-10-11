#ifndef _MEMORYADDRESS_CPP
#define _MEMORYADDRESS_CPP

#include "MemoryAddress.h"
#include "Processor.h"

MemoryAddress::MemoryAddress () {

}

MemoryAddress::~MemoryAddress () {

}

void MemoryAddress::processSignal () {
	if (microinstruction->LMR)
		this->setContent(databus->getContent());
}

#endif
