/*
 * This file is part of Std-Arch-Sim.
 *
 * Std-Arch-Sim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Std-Arch-Sim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Std-Arch-Sim.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _MICROPROGRAMSEQUENCER_CPP
#define _MICROPROGRAMSEQUENCER_CPP

#include "MicroprogramSequencer.h"
#include "Processor.h"

MicroprogramSequencer::MicroprogramSequencer () {

}

MicroprogramSequencer::~MicroprogramSequencer () {

}

/*
void MicroprogramSequencer::processSignal () {
	if (microinstruction->LMS)
		this->setContent(decoder->getContent());
	if (microinstruction->RMS && !microinstruction->EFL) // @Ghosh : Unconditional reset, if EFL == false;
		this->setContent(RESET_ADDRESS);
	if (microinstruction->RMS && microinstruction->EFL) // @Ghosh : Conditional reset, if flag is enabled;
		if (flag->getFlag())
			this->setContent(RESET_ADDRESS);
}
*/

void MicroprogramSequencer::processSignalRisingEdge(){	
}

void MicroprogramSequencer::processSignalFallingEdge(){	
	if (microinstruction->RMS && !microinstruction->EFL){ // @Ghosh : Unconditional reset, if EFL == false;
		std::cout << "RMS w/o flag\n";
		this->setContent(RESET_ADDRESS);
		this->clockPulse();
	}
	if (microinstruction->RMS && microinstruction->EFL){ // @Ghosh : Conditional reset, if flag is enabled;
		std::cout << "RMS w/t flag\n";
		if (flag->getFlag()) {
			this->setContent(RESET_ADDRESS);
			this->clockPulse();
		}
	}
	if (microinstruction->LMS){
		std::cout << "LMS\n";
		this->setContent(decoder->getContent());
		this->clockPulse();
	}
}

void MicroprogramSequencer::clockPulse () {
	if (!microinstruction->RMS && !microinstruction->LMS)
		this->increment();
	Register::clockPulse();
}

void MicroprogramSequencer::updateImmediate () {
	Register::clockPulse();
}

#endif
