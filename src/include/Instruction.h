#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

#include "BaseRegister.h"

class Instruction : public Register {
	private:
	public:
		Instruction();
		~Instruction();
		void processSignalRisingEdge();
		void processSignalFallingEdge();
};

#endif
