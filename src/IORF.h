#ifndef _IORF_H
#define _IORF_H

#include "BaseRegister.h"

class IO_RF : public Register {
	private:
	public:
		int SRG;
		int SFL;
		IO_RF();
		~IO_RF();

		void processSignal();
		void clockPulse();
};

#endif
