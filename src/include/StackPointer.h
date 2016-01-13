#ifndef _STACKPOINTER_H
#define _STACKPOINTER_H

#include "BaseRegister.h"
#include "Microinstruction.h"
#include "Databus.h"
#include <iostream>

class StackPointer : public Register {
	private:
	public:
		StackPointer() {
			this->Content = -1; // Becomes 255 on getContent()
		}
		
		~StackPointer() {}

		void processSignalRisingEdge(Microinstruction *microinstruction, Databus *databus) {
			if (microinstruction->ESP) {
				std::cout << "ESP\t";
				databus->setContent(this->getContent());
			}
		}
		void processSignalFallingEdge(Microinstruction *microinstruction, Databus *databus) {
			if (microinstruction->ISP) {
				std::cout << "ISP\t";
				this->increment();
			}
			if (microinstruction->DSP) {
				std::cout << "DSP\t";
				this->decrement();
			}
			if (microinstruction->LSP) {
				std::cout << "LSP\t";
				this->setContent(databus->getContent());
			}
		}
};

#endif
