#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

#include "Processor.h"

Accumulator *accumulator = new Accumulator();
Databus *databus = new Databus();
ALU *alu = new ALU();

int main(int argc, char const *argv[])
{
	std::cout <<databus->getContent()<<std::endl;
	std::cout <<accumulator->getContent()<<std::endl;

	accumulator->setContent( 10 );

	EAR();

	std::cout <<accumulator->getContent()<<std::endl;
	std::cout <<databus->getContent()<<std::endl;

	delete accumulator;
	delete databus;
	delete alu;
	return 0;
}
