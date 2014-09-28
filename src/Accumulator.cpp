#ifndef _ACCUMULATOR_CPP
#define _ACCUMULATOR_CPP

#include "Accumulator.h"
#include "Processor.h"

Accumulator::Accumulator () {
	this->Content = 0;
}

Accumulator::~Accumulator () {

}

void Accumulator::setContent ( int content ) {
	this->Content = content;
}

int Accumulator::getContent () {
	return this->Content & 255;
}

#endif
