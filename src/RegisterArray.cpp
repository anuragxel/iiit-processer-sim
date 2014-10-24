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

void RegisterArray::processSignal () {
	if (microinstruction->ERG) {
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
	if (microinstruction->LRG) {
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

void StackPointer::processSignalUpwardEdge(){

}

void StackPointer::processSignalDownwardEdge(){
	
}

void RegisterArray::clockPulse () {
	for (auto &i : registerArray)
		i.clockPulse();
}

void RegisterArray::setContent ( int content ) {
	registerArray[io->SRG].setContent (content);
}

int RegisterArray::getContent() {
	return registerArray[io->SRG].getContent();
}

#endif
