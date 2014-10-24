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
#ifndef _OPERAND_CPP
#define _OPERAND_CPP

#include "Operand.h"
#include "Processor.h"

Operand::Operand () {

}

Operand::~Operand () {

}

/*
void Operand::processSignal () {
	if (microinstruction->EOR)
		databus->setContent(this->getContent());
	if (microinstruction->ROR)
		this->setContent(0);
	if (microinstruction->LOR)
		this->setContent(databus->getContent());
}
*/
void Operand::processSignalRisingEdge(){
	if (microinstruction->EOR){
		std::cout << "EOR\n";
		databus->setContent(this->getContent());
	}
}

void Operand::processSignalFallingEdge(){
	if (microinstruction->ROR){
		std::cout << "ROR\n";
		this->setContent(0);
	}
	if (microinstruction->LOR) {
		std::cout << "LOR\n";
		this->setContent(databus->getContent());
	}
}

#endif
