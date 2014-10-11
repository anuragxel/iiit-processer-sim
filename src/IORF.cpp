#ifndef _IORF_CPP
#define _IORF_CPP

#include "IORF.h"
#include "Processor.h"

IO_RF::IO_RF () {

}

IO_RF::~IO_RF () {

}

void IO_RF::processSignal () {
	if (microinstruction->LIO) {
		this->setContent(databus->getContent());
	}
}

void IO_RF::clockPulse () {
	Register::clockPulse();
	this->SRG = this->Content & 15;
	this->SFL = this->Content & 7;
}

#endif
