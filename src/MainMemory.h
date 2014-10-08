#ifndef _MAINMEMORY_H
#define _MAINMEMORY_H

#include <array>
#include <string>
#include <fstream>

class MainMemory
{
	private:
		std::array<char, 256> mainMemory;
	public:
		MainMemory();
		~MainMemory();

		MainMemory(std::string);
		MainMemory(std::fstream);
		MainMemory(std::ifstream);

		void setContent( int );
		int getContent ( );
};

#endif
