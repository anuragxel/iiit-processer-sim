#ifndef _PROGRAMCOUNTER_H
#define _PROGRAMCOUNTER_H

#include "BaseRegister.h"
#include "Microinstruction.h"
#include "Databus.h"
#include <iostream>

class ProgramCounter : public Register {
	private:
	public:
		ProgramCounter() {}
		~ProgramCounter() {}
		void processSignalRisingEdge(Microinstruction *microinstruction, Databus *databus) {
			if (microinstruction->EPC){
				std::cout << "EPC\t";
				databus->setContent(this->getContent());
			}
		}
		void processSignalFallingEdge(Microinstruction *microinstruction, Databus *databus) {
			if (microinstruction->IPC) {
				std::cout << "IPC\t";
				this->increment();
			}
			if (microinstruction->LPC) {
				std::cout << "LPC\t";
				this->setContent(databus->getContent());
			}
		}	
};

#endif
