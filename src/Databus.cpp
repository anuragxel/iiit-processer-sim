#ifndef _DATABUS_CPP
#define _DATABUS_CPP

#include "Databus.h"
#include "Processor.h"

Databus::Databus () {
	this->Content = 0;
	this->Busy = true;
}

Databus::~Databus () {

}

void Databus::setContent ( int content ) {
	this->Content = content;
}

int Databus::getContent () {
	return this->Content & 255;
}

bool Databus::isBusy() {
	return this->Busy == true;
};

void Databus::setBusy() {
	this->Busy = true;
};

void Databus::resetBusy() {
	this->Busy = false;
};

void Databus::setBusy( bool busy ) {
	this->Busy = busy;
};

bool Databus::getBusy () {
	return this->Busy;
};

#endif
