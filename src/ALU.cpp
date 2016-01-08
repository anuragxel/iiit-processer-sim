#ifndef _ALU_CPP
#define _ALU_CPP

#include "include/ALU.h"
#include "include/Processor.h"

ALU::ALU () {

}

ALU::~ALU () {

}

//
// PARTH ---> ALU WORKS ULTA :P So rha tha kya ? :P
//
/*
 * Does Databus.value() {op} Operand.value()
 * And sets subsequent bits in the Flag Register.
 */
int ALU::getContent() { // for pseudo-content
	int unpadded_bit = databus->getContent();
	bool arithmatic = false;
	switch ((microinstruction->SAF) & 0x0F) {
		case 0x01:
			// Addition
			arithmatic = true;
			unpadded_bit = unpadded_bit + operand->getContent();
			break;
		case 0x02:
			// Subtraction
			arithmatic = true;
			unpadded_bit = unpadded_bit - operand->getContent();
			break;
		case 0x03:
			// xoring
			unpadded_bit = unpadded_bit ^ operand->getContent();
			break;
		case 0x04:
			unpadded_bit = unpadded_bit & operand->getContent();
			break;
		case 0x05:
			unpadded_bit = unpadded_bit | operand->getContent();
			break;
		case 0x06:
			arithmatic = true;
			unpadded_bit = unpadded_bit - operand->getContent();
			break;
		case 0x0F:
			//unpadded_bit = databus->getContent();
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
