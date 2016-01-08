/*
 * This file is part of Std-Arch-Sim.
 *
 * Std-Arch-Sim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Std-Arch-Sim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Std-Arch-Sim.  If not, see <http://www.gnu.org/licenses/>.
 */
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
