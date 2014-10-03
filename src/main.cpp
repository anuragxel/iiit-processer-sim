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

int main(int argc, char const *argv[]) {


	delete accumulator;
	delete alu;
	delete databus;
	delete microinstruction;
	delete operand;
	return 0;
}
