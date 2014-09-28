#ifndef _ALU_CPP
#define _ALU_CPP

#include "ALU.cpp"
#include "Processor.h"

ALU::ALU () {
	this->Content = 0;
}

ALU::~ALU () {

}

void ALU::setContent ( int content ) {
	this->Content = content;
}

int ALU::getContent () {
	return this->Content & 255;
}

#endif
