#ifndef _MICROPROGRAMSEQUENCER_H
#define _MICROPROGRAMSEQUENCER_H

#include "BaseRegister.h"

class MicroprogramSequencer : public Register {
	private:
	public:
		MicroprogramSequencer();
		~MicroprogramSequencer();

		void clockPulse();
		void processSignalRisingEdge();
		void processSignalFallingEdge();
		void updateImmediate();
};

#endif
