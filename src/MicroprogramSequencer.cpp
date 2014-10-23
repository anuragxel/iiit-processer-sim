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
#ifndef _MICROPROGRAMSEQUENCER_CPP
#define _MICROPROGRAMSEQUENCER_CPP

#include "MicroprogramSequencer.h"
#include "Processor.h"

MicroprogramSequencer::MicroprogramSequencer () {

}

MicroprogramSequencer::~MicroprogramSequencer () {

}

void MicroprogramSequencer::processSignal () {
	if (microinstruction->LMS)
		this->setContent(instruction->getContent());
	if (microinstruction->RMS && !flag->getFlag())
		this->setContent(0);
}

#endif
