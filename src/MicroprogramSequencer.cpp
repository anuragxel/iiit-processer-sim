#ifndef _MICROPROGRAMSEQUENCER_CPP
#define _MICROPROGRAMSEQUENCER_CPP

#include "include/MicroprogramSequencer.h"
#include "include/Processor.h"

MicroprogramSequencer::MicroprogramSequencer () {

}

MicroprogramSequencer::~MicroprogramSequencer () {

}

void MicroprogramSequencer::processSignalRisingEdge(){
}

void MicroprogramSequencer::processSignalFallingEdge(){
	if (microinstruction->RMS == true && microinstruction->EFL == false){ // @Ghosh : Unconditional reset, if EFL == false;
		std::cout << "RMS w/o flag\t";
		this->setContent(RESET_ADDRESS);
		this->clockPulse();
	}
	if (microinstruction->RMS == true && microinstruction->EFL == true){ // @Ghosh : Conditional reset, if flag is enabled;
		if (  flag->getFlag() ) {
			std::cout << "RMS w/t flag\t";
			this->setContent(RESET_ADDRESS);
			this->clockPulse();
		}
	}
	if (microinstruction->LMS){
		std::cout << "LMS\t";
		this->setContent(decoder->getContent());
		this->clockPulse();
	}
}

void MicroprogramSequencer::clockPulse () {
	if (!microinstruction->RMS && !microinstruction->LMS)
		this->increment();
}

void MicroprogramSequencer::updateImmediate () {
	Register::clockPulse();
}

#endif
