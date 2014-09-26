#ifndef _ACCUMULATOR_CPP
#define _ACCUMULATOR_CPP

#include "Accumulator.h"

Accumulator::Accumulator () {
	this->content = 0;
}

Accumulator::~Accumulator () {

}

void Accumulator::setContent ( int content ) {
	this->Content = content;
}

int Accumulator::getContent () {
	return this->Content;
}

#endif