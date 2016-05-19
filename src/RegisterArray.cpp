#ifndef _REGISTERARRAY_CPP
#define _REGISTERARRAY_CPP

#include <iostream>

#include "include/RegisterArray.h"
#include "include/Processor.h"

void RegisterArray::processSignalRisingEdge() {
	if (microinstruction->ERG) {
		std::cout << "ERG\t";
		switch (io->SRG) {
			case 15:
				databus->setContent(operand->getContent());
				break;
			case 14:
				databus->setContent(accumulator->getContent());
				break;
			case 13:
				databus->setContent(stackPointer->getContent());
				break;
			case 12:
				databus->setContent(programCounter->getContent());
			default:
				databus->setContent(registerArray[io->SRG].getContent());
				break;
		}
	}
}

void RegisterArray::processSignalFallingEdge(){
	if (microinstruction->LRG) {
		std::cout << "LRG\t";
		switch (io->SRG) {
			case 15:
				operand->setContent(databus->getContent());
				break;
			case 14:
				accumulator->setContent(databus->getContent());
				break;
			case 13:
				stackPointer->setContent(databus->getContent());
				break;
			case 12:
				programCounter->setContent(databus->getContent());
			default:
				registerArray[io->SRG].setContent(databus->getContent());
				break;
		}
	}
}

void RegisterArray::clockPulse () {
	for (auto &i : registerArray)
		i.clockPulse();
}

// this implies that io register must be set
// before register array.
void RegisterArray::setContent ( int content ) {
	registerArray[io->SRG].setContent(content);
}

int RegisterArray::getContent() {
	return registerArray[io->SRG].getContent();
}

std::string RegisterArray::toString() {
	std::string buff;
	for (auto &i : registerArray) {
		buff +=  i.toString();
		buff += "\t";
	}
	return buff;
}

#endif
