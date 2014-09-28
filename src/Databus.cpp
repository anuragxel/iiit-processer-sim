#ifndef _DATABUS_CPP
#define _DATABUS_CPP

#include "Databus.h"
#include "Processor.h"

Databus::Databus () {
	this->Content = 0;
}

Databus::~Databus () {

}

void Databus::setContent ( int content ) {
	this->Content = content;
}

int Databus::getContent () {
	return this->Content & 255;
}

#endif
