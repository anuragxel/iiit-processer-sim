#ifndef _STACKPOINTER_H
#define _STACKPOINTER_H

#include "BaseRegister.h"

class StackPointer : public Register {
	private:
	public:
		StackPointer();
		~StackPointer();
		void processSignal();
};

#endif
