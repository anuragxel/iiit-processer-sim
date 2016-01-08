#ifndef _ROM_H
#define _ROM_H

#include "Microinstruction.h"
#include <vector>
#include <fstream>
#include <string>

class ROM
{
	private:
		std::vector<Microinstruction> hashTable;
	public:
		ROM();
		~ROM();

		ROM(std::string);
		ROM(std::fstream);
		ROM(std::ifstream);

		void setMicroinstruction();
};

#endif
