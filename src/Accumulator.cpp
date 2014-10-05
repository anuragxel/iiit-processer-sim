#ifndef _ACCUMULATOR_CPP
#define _ACCUMULATOR_CPP

#include "Accumulator.h"
#include "Processor.h"

Accumulator::Accumulator () {

}

Accumulator::~Accumulator () {

}

void Accumulator::processSignal () {
	if (microinstruction->EAR)
		databus->setContent(this->getContent());
	if (microinstruction->RAR)
		this->setContent(0);
	if (microinstruction->LAR)
		this->setContent(alu->getContent());
}

#endif
