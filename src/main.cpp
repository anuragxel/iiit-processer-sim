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
Microinstruction *microinstruction = new Microinstruction();
Operand *operand = new Operand();
Flag *flag = new Flag();

int main(int argc, char const *argv[]) {

	// operand->setContent( 0 );
	// databus->setContent( 127 );
	// operand->clockPulse();
	// microinstruction->SAF = 1;
	// std::cout <<alu->getContent()<<std::endl;
	// std::cout <<flag->getC()<<std::endl;
	// std::cout <<flag->getS()<<std::endl;
	// std::cout <<flag->getNS()<<std::endl;


	//	flag->setS();
	//	std::cout <<flag->getS();
	//	flag->resetS();
	//	std::cout <<flag->getS();
	//	std::cout <<flag->getU();

	//	databus->setContent( 10 );
	//	operand->setContent ( 20 );
	//	operand->clockPulse();
	//	microinstruction->SAF = 1;
	//	std::cout <<(microinstruction->SAF & 15)<<std::endl;
	//	std::cout <<alu->getContent()<<std::endl;

	delete accumulator;
	delete alu;
	delete databus;
	delete flag;
	delete microinstruction;
	delete operand;
	return 0;
}
