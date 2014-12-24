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
#ifndef _REGISTERARRAY_CPP
#define _REGISTERARRAY_CPP

#include <iostream>

#include "RegisterArray.h"
#include "Processor.h"

RegisterArray::RegisterArray () {

}

RegisterArray::~RegisterArray () {

}

void RegisterArray::processSignalRisingEdge(){
	if (microinstruction->ERG) {
		std::cout << "ERG\t";
		switch (io->SRG) {
			case 15:
				databus->setContent(operand->getContent());
				break;
			case 14:
				databus->setContent(accumulator->getContent());
				break;
			case 13:
				databus->setContent(stackPointer->getContent());
				break;
			case 12:
				databus->setContent(programCounter->getContent());
			default:
				databus->setContent(registerArray[io->SRG].getContent());
				break;
		}
	}
}

void RegisterArray::processSignalFallingEdge(){
	if (microinstruction->LRG) {
		std::cout << "LRG\t";
		switch (io->SRG) {
			case 15:
				operand->setContent(databus->getContent());
				break;
			case 14:
				accumulator->setContent(databus->getContent());
				break;
			case 13:
				stackPointer->setContent(databus->getContent());
				break;
			case 12:
				programCounter->setContent(databus->getContent());
			default:
				registerArray[io->SRG].setContent(databus->getContent());
				break;
		}
	}
}

void RegisterArray::clockPulse () {
	for (auto &i : registerArray)
		i.clockPulse();
}

// this implies that io register must be set
// before register array. 

void RegisterArray::setContent ( int content ) {
	registerArray[io->SRG].setContent(content);
}

int RegisterArray::getContent() {
	return registerArray[io->SRG].getContent();
}

std::string RegisterArray::toString() {
	std::string buff;
	int j=0;
	for (auto &i : registerArray) {
		buff += "r" + std::to_string(j) + " : " + i.toString() + "\t";
		j++;
		if(j == 6 || j == 12)
			buff += '\n';		
	}
	return buff;
}

#endif
