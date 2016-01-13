#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

#include "BaseRegister.h"
#include "Microinstruction.h"
#include "Databus.h"
#include <iostream>


class Instruction : public Register {
	private:
	public:
		Instruction() {}
		~Instruction() {}
		void processSignalRisingEdge() {}
		void processSignalFallingEdge(Microinstruction *microinstruction, Databus *databus) {
			if (microinstruction->LIR){
				std::cout << "LIR\t";
				this->setContent(databus->getContent());
			}
		}
};

#endif
