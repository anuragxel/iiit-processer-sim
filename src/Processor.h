#ifndef PROCESSOR_H
#define PROCESSOR_H

#define _BIT ( integer , position ) (( integer >> position) & 1)
#define _isSET ( integer , position ) _BIT ( integer , position ) == 1
#define CORRUPT_BIT_SET 1
#define INVALID_STREAM 2
#define FILE_NOT_READABLE 407 //File not found or Permission denied. => 404 | 403 => 407. (Not to be confused with proxy auth fail.)

#include "Accumulator.h"
#include "ALU.h"
#include "Databus.h"
#include "Flag.h"
#include "IORF.h"
#include "MainMemory.h"
#include "MemoryAddress.h"
#include "Microinstruction.h"
#include "Operand.h"
#include "ProgramCounter.h"
#include "RegisterArray.h"
#include "StackPointer.h"

extern Accumulator *accumulator;
extern ALU *alu;
extern Databus *databus;
extern Flag *flag;
extern IO_RF *io;
extern MainMemory *mainMemory;
extern MemoryAddress *memoryAddress;
extern Microinstruction *microinstruction;
extern Operand *operand;
extern ProgramCounter *programCounter;
extern RegisterArray *registerArray;
extern StackPointer *stackPointer;

#endif
