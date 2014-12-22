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
#ifndef _IORF_CPP
#define _IORF_CPP

#include "IORF.h"
#include "Processor.h"

IO_RF::IO_RF () {

}

IO_RF::~IO_RF () {

}

void IO_RF::processSignalRisingEdge(){

}

void IO_RF::processSignalFallingEdge(){
	if (microinstruction->LIO) {
		std::cout << "LIO\t";
		this->setContent(databus->getContent());
	}
}

void IO_RF::clockPulse () {
	Register::clockPulse();
	this->SRG = this->Content & 0x0F;
	this->SFL = this->Content & 0x07;
}

#endif
