#ifndef _MICROPROGRAMSEQUENCER_H
#define _MICROPROGRAMSEQUENCER_H

#include "BaseRegister.h"

class MicroprogramSequencer : public Register {
	private:
	public:
		MicroprogramSequencer() {}
		~MicroprogramSequencer() {}

		void clockPulse(Microinstruction *microinstruction) {
			if (!microinstruction->RMS && !microinstruction->LMS)
				this->increment();
		}
		void processSignalFallingEdge(Microinstruction *microinstruction, IO_RF *io, Flag* flag, Decoder *decoder) {
			if (microinstruction->RMS == true && microinstruction->EFL == false){ // @Ghosh : Unconditional reset, if EFL == false;
				std::cout << "RMS w/o flag\t";
				this->setContent(RESET_ADDRESS);
				this->clockPulse(microinstruction);
			}
			if (microinstruction->RMS == true && microinstruction->EFL == true){ // @Ghosh : Conditional reset, if flag is enabled;
				if (  flag->getFlag(io) ) {
						std::cout << "RMS w/t flag\t";
						this->setContent(RESET_ADDRESS);
						this->clockPulse(microinstruction);
				}
				else { // Flag is not set, go ahead
					// I hate this, if it doesn't end, it needs to go the next one.
					this->increment();
				}
			}
			if (microinstruction->LMS){
				std::cout << "LMS\t";
				this->setContent(decoder->getContent());
				this->clockPulse(microinstruction);
			}
		}

		void updateImmediate() {
			Register::clockPulse(); // bug, et tu ?
		}
};

#endif
