#ifndef _OPERAND_H
#define _OPERAND_H

#include "BaseRegister.h"
#include "Microinstruction.h"
#include "Databus.h"
#include <iostream>

class Operand : public Register {
	private:
	public:
		Operand() {}
		~Operand() {}
		void processSignalRisingEdge(Microinstruction *microinstruction, Databus *databus) {
			if (microinstruction->EOR){
				std::cout << "EOR\t";
				databus->setContent(this->getContent());
			}
		}

		void processSignalFallingEdge(Microinstruction *microinstruction, Databus *databus) {
			if (microinstruction->ROR){
				std::cout << "ROR\t";
				this->setContent(0);
			}
			if (microinstruction->LOR) {
				std::cout << "LOR\t";
				this->setContent(databus->getContent());
			}
		}
};

#endif
