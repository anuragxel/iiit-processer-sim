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


	delete accumulator;
	delete databus;
	delete alu;
	return 0;
}
