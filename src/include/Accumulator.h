#ifndef _ACCUMULATOR_H
#define _ACCUMULATOR_H

#include "BaseRegister.h"
#include "Microinstruction.h"
#include "Databus.h"
#include "ALU.h"
#include <iostream>

class Accumulator : public Register {
	private:
	public:
		Accumulator() {}
		~Accumulator() {}
		void processSignalRisingEdge(Microinstruction *microinstruction, Databus *databus) {
			if(microinstruction->EAR) {
				std::cout << "EAR\t";
				databus->setContent(this->getContent());
			}
		}
		void processSignalFallingEdge(Microinstruction *microinstruction, ALU *alu) {
			if (microinstruction->RAR){
				std::cout << "RAR\t";
				this->setContent(0);
			}
			if (microinstruction->LAR){
				std::cout << "LAR\t";
				this->setContent(alu->getContent());
			}
		}		
};

#endif
