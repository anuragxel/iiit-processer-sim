#ifndef _CONTROL_SIGNALS_H
#define _CONTROL_SIGNALS_H

#include "Processor.h"

extern ALU *alu;
extern Databus *databus;
extern Accumulator *accumulator;

void EAR();
void RAR();
void LAR();

#endif
