#ifndef _MEMORYADDRESS_H
#define _MEMORYADDRESS_H

#include "BaseRegister.h"

class MemoryAddress : public Register {
	private:
	public:
		MemoryAddress();
		~MemoryAddress();
		void processSignal();
};

#endif
