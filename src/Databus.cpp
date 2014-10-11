#ifndef _DATABUS_CPP
#define _DATABUS_CPP

#include "Databus.h"
#include "Processor.h"

Databus::Databus () {
	this->Content = 0;
	this->Busy = false;
	this->Corrupt = false;
}

Databus::~Databus () {

}

void Databus::setContent ( int content ) {
	if (this->Busy){
		this->Corrupt = true;
		throw CORRUPT_BIT_SET;
	}
	this->Content = content;
	this->Busy = true;
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

void Databus::resetCorrupt () {
	this->Corrupt = false;
}

#endif
