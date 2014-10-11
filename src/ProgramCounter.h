#ifndef _PROGRAMCOUNTER_H
#define _PROGRAMCOUNTER_H

#include "BaseRegister.h"

class ProgramCounter : public Register {
	private:
	public:
		ProgramCounter();
		~ProgramCounter();
		void processSignal();
};

#endif
