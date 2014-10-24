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
#ifndef _MICROINSTRUCTION_CPP
#define _MICROINSTRUCTION_CPP

#include "Microinstruction.h"
#include "Processor.h"

Microinstruction::Microinstruction () {
	this->RD = false;
	this->WR = false;
	this->LMR = false;
	this->EPC = false;
	this->IPC = false;
	this->LPC = false;
	this->ESP = false;
	this->ISP = false;
	this->DSP = false;
	this->LSP = false;
	this->LIR = false;
	this->LMS = false;
	this->RMS = false;
	this->EFL = false;
	this->LIO = false;
	this->LRG = false;
	this->ERG = false;
	this->LAR = false;
	this->RAR = false;
	this->EAR = false;
	this->SAF = 0;
	this->LOR = false;
	this->ROR = false;
	this->EOR = false;
}

Microinstruction::~Microinstruction() {

}

void Microinstruction::setContent(Microinstruction content) {
	this->RD = content.RD;
	this->WR = content.WR;
	this->LMR = content.LMR;
	this->EPC = content.EPC;
	this->IPC = content.IPC;
	this->LPC = content.LPC;
	this->ESP = content.ESP;
	this->ISP = content.ISP;
	this->DSP = content.DSP;
	this->LSP = content.LSP;
	this->LIR = content.LIR;
	this->LMS = content.LMS;
	this->RMS = content.RMS;
	this->EFL = content.EFL;
	this->LIO = content.LIO;
	this->LRG = content.LRG;
	this->ERG = content.ERG;
	this->LAR = content.LAR;
	this->RAR = content.RAR;
	this->EAR = content.EAR;
	this->SAF = content.SAF;
	this->LOR = content.LOR;
	this->ROR = content.ROR;
	this->EOR = content.EOR;
}

void Microinstruction::resetContent() {
	this->RD = false;
	this->WR = false;
	this->LMR = false;
	this->EPC = false;
	this->IPC = false;
	this->LPC = false;
	this->ESP = false;
	this->ISP = false;
	this->DSP = false;
	this->LSP = false;
	this->LIR = false;
	this->LMS = false;
	this->RMS = false;
	this->EFL = false;
	this->LIO = false;
	this->LRG = false;
	this->ERG = false;
	this->LAR = false;
	this->RAR = false;
	this->EAR = false;
	this->SAF = 0;
	this->LOR = false;
	this->ROR = false;
	this->EOR = false;
}

#endif
