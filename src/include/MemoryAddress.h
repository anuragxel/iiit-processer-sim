#ifndef _MEMORYADDRESS_H
#define _MEMORYADDRESS_H

#include "BaseRegister.h"
#include "Microinstruction.h"
#include "Databus.h"
#include <iostream>


class MemoryAddress : public Register {
	private:
	public:
		MemoryAddress() {}
		~MemoryAddress() {}
		void processSignalRisingEdge() {}
		void processSignalFallingEdge(Microinstruction *microinstruction, Databus *databus) {
			if (microinstruction->LMR){
				std::cout << "LMR\t";
				this->setContent(databus->getContent());
			}
		}
		void updateImmediate() {
			Register::clockPulse();
		}
};

#endif
