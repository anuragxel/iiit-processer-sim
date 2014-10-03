#ifndef PROCESSOR_H
#define PROCESSOR_H

#define _BIT ( integer , position ) (( integer >> position) & 1)
#define _isSET ( integer , position ) _BIT ( integer , position ) == 1

#include "Accumulator.h"
#include "ALU.h"
#include "Databus.h"
#include "Microinstruction.h"
#include "Operand.h"

extern Accumulator *accumulator;
extern ALU *alu;
extern Databus *databus;
extern Microinstruction *microinstruction;
extern Operand *operand;

#endif
