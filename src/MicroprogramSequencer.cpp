#ifndef _MICROPROGRAMSEQUENCER_CPP
#define _MICROPROGRAMSEQUENCER_CPP

#include "MicroprogramSequencer.h"
#include "Processor.h"

MicroprogramSequencer::MicroprogramSequencer () {

}

MicroprogramSequencer::~MicroprogramSequencer () {

}

void MicroprogramSequencer::processSignal () {
	if (microinstruction->LMS)
		this->setContent(instruction->getContent());
	if (microinstruction->RMS && !flag->getFlag())
		this->setContent(0);
}

#endif
