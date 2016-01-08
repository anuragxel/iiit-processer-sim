#ifndef _REGISTERARRAY_H
#define _REGISTERARRAY_H

#include "BaseRegister.h"
#include <array>
#include <string>

class RegisterArray {
	private:
		std::array<Register , 12> registerArray;
	public:
		RegisterArray();
		~RegisterArray();
		void processSignalRisingEdge();
		void processSignalFallingEdge();
		void clockPulse();
		void setContent (int);
		int getContent();
		std::string toString();
};

#endif
