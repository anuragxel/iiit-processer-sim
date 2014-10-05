#ifndef _ALU_CPP
#define _ALU_CPP

#include "ALU.h"
#include "Processor.h"

ALU::ALU () {

}

ALU::~ALU () {

}

int ALU::getContent() { // for pseudo-content
	int unpadded_bit = operand->getContent();
	bool arithmatic = false;
	switch ((microinstruction->SAF) & 15) {
		case 1:
			arithmatic = true;
			unpadded_bit = unpadded_bit + databus->getContent();
			break;
		case 2:
			arithmatic = true;
			unpadded_bit = unpadded_bit - databus->getContent();
			break;
		case 3:
			unpadded_bit = unpadded_bit ^ databus->getContent();
			break;
		case 4:
			unpadded_bit = unpadded_bit & databus->getContent();
			break;
		case 5:
			unpadded_bit = unpadded_bit | databus->getContent();
			break;
		case 6:
			arithmatic = true;
			unpadded_bit = unpadded_bit - databus->getContent();
			break;
		case 15:
			unpadded_bit = databus->getContent();
			break;
	}

	char padded_bit = (char) unpadded_bit;

	if (arithmatic)
	{
		if (unpadded_bit < 0) {
			flag->setS();
		}
		else {
			flag->resetS();
		}

		if (unpadded_bit > 0) {
			flag->setNS();
		}
		else {
			flag->resetNS();
		}

		if (padded_bit == unpadded_bit) {
			flag->resetC();
			flag->setNC();
		}
		else {
			flag->setC();
			flag->resetNC();
		}
	}

	if (unpadded_bit == 0)
	{
		flag->setZ();
		flag->resetNZ();
	}

	unpadded_bit = padded_bit; // Because I did not want to make extra variable just for pairity check;
	bool pairity = false;

	while (unpadded_bit)
	{
		pairity = !pairity;
		unpadded_bit = unpadded_bit & (unpadded_bit - 1);
	}

	if (pairity) {
		flag->setP();
	}
	else {
		flag->resetP();
	}

	return (int)padded_bit;
}

#endif
