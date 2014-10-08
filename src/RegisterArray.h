#ifndef _REGISTERARRAY_H
#define _REGISTERARRAY_H

#include "BaseRegister.h"
#include <array>

class RegisterArray {
	private:
		std::array<Register , 12> registerArray;
	public:
		RegisterArray();
		~RegisterArray();
		void processSignal();
		void clockPulse();
		void setContent (int);
		int getContent();
};

#endif
