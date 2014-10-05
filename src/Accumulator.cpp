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
		databus->setContent(this->Content);
	if (microinstruction->RAR)
		this->Content = 0;
	if (microinstruction->LAR)
		this->Content = alu->getContent();
}

#endif
