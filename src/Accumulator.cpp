#ifndef _ACCUMULATOR_CPP
#define _ACCUMULATOR_CPP

#include "Accumulator.h"
#include "Processor.h"

extern Databus databus;
extern Accumulator accumulator;
extern ALU alu;

Accumulator::Accumulator () {
	this->Content = 0;
}

Accumulator::~Accumulator () {

}

void Accumulator::setContent ( int content ) {
	this->Content = content;
}

int Accumulator::getContent () {
	return this->Content & ~((1 << 9) - 1);
}

void EAR ()
{
	databus.setContent(accumulator.getContent());
}

void RAR ()
{
	accumulator.setContent( 0 );
}

void LAR ()
{
	accumulator.setContent(alu.getContent());
}
#endif
