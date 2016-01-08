#ifndef _OPERAND_H
#define _OPERAND_H

#include "BaseRegister.h"

class Operand : public Register {
	private:
	public:
		Operand();
		~Operand();
		void processSignalRisingEdge();
		void processSignalFallingEdge();
};

#endif
