#ifndef _IORF_CPP
#define _IORF_CPP

#include "include/IORF.h"
#include "include/Processor.h"

IO_RF::IO_RF () {

}

IO_RF::~IO_RF () {

}

void IO_RF::processSignalRisingEdge(){

}

void IO_RF::processSignalFallingEdge(){
	if (microinstruction->LIO) {
		std::cout << "LIO\t";
		this->setContent(databus->getContent());
	}
}

void IO_RF::clockPulse () {
	Register::clockPulse(); // what the fuck ??
	this->SRG = this->Content & 0x0F;
	this->SFL = this->Content & 0x07;
}

#endif
