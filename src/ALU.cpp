#ifndef _ALU_CPP
#define _ALU_CPP

#include "ALU.h"
#include "Processor.h"

ALU::ALU () {

}

ALU::~ALU () {

}

int ALU::getContent() { // for pseudo-content
	switch ((microinstruction->SAF) & 15)
	{
		case 1:
			return operand->getContent() + databus->getContent();
		case 2:
			return operand->getContent() - databus->getContent();
		case 3:
			return operand->getContent() ^ databus->getContent();
		case 4:
			return operand->getContent() & databus->getContent();
		case 5:
			return operand->getContent() | databus->getContent();
		case 6:
			return operand->getContent() < databus->getContent();
		case 15:
			return databus->getContent();
	}
}

#endif
