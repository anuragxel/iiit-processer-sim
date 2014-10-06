#ifndef _REGISTERARRAY_CPP
#define _REGISTERARRAY_CPP

#include <iostream>

#include "RegisterArray.h"
#include "Processor.h"

RegisterArray::RegisterArray () {

}

RegisterArray::~RegisterArray () {

}

void RegisterArray::processSignal () {
	if (microinstruction->ERG)
		databus->setContent(registerArray[io->SRG].getContent());
	if (microinstruction->LRG)
		registerArray[io->SRG].setContent(databus->getContent());
}

void RegisterArray::clockPulse () {
	for (auto &i : registerArray)
		i.clockPulse();
}

void RegisterArray::setContent ( int content ) {
	registerArray[io->SRG].setContent (content);
}

int RegisterArray::getContent() {
	return registerArray[io->SRG].getContent();
}

#endif
