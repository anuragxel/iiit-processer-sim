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
#ifndef _PROGRAMCOUNTER_CPP
#define _PROGRAMCOUNTER_CPP

#include "ProgramCounter.h"
#include "Processor.h"

ProgramCounter::ProgramCounter () {

}

ProgramCounter::~ProgramCounter () {

}

/*
void ProgramCounter::processSignal () {
	if (microinstruction->EPC)
		databus->setContent(this->getContent());
	if (microinstruction->IPC)
		this->increment();
	if (microinstruction->LPC)
		this->setContent(databus->getContent());
}
*/
void ProgramCounter::processSignalRisingEdge(){
	if (microinstruction->EPC){
		std::cout << "EPC\n";
		databus->setContent(this->getContent());
	}
}

void ProgramCounter::processSignalFallingEdge(){
	if (microinstruction->IPC) {
		std::cout << "IPC\n";
		this->increment();
	}
	if (microinstruction->LPC) {
		std::cout << "LPC\n";
		this->setContent(databus->getContent());
	}
}

#endif
