#ifndef _IORF_H
#define _IORF_H

#include "BaseRegister.h"

class IO_RF : public Register {
	private:
	public:
		int SRG;
		int SFL;
		IO_RF() {}
		~IO_RF() {}


		void processSignalFallingEdge(Microinstruction *microinstruction, Databus *databus) {
			if (microinstruction->LIO) {
				std::cout << "LIO\t";
				this->setContent(databus->getContent());
			}
		}

		void clockPulse()  {
			Register::clockPulse(); // what the fuck ??
			this->SRG = this->Content & 0x0F;
			this->SFL = this->Content & 0x07;
		}
};

#endif
