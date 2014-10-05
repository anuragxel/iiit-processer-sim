#ifndef _MICROINSTRUCTION_CPP
#define _MICROINSTRUCTION_CPP

#include "Microinstruction.h"
#include "Processor.h"

Microinstruction::Microinstruction () {
	RD = false;
	WR = false;
	LMR = false;
	EPC = false;
	IPC = false;
	LPC = false;
	ESP = false;
	ISP = false;
	DSP = false;
	LSP = false;
	LIR = false;
	LMS = false;
	RMS = false;
	EFL = false;
	LIO = false;
	LRG = false;
	ERG = false;
	SRG = 0;
	LAR = false;
	RAR = false;
	EAR = false;
	SAF = 0;
	LOR = false;
	ROR = false;
	EOR = false;
}

Microinstruction::~Microinstruction() {

}

#endif
