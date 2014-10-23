/*
 * This file is part of Std-Arch-Sim.
 *
 * Std-Arch-Sim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Std-Arch-Sim.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _DATABUS_CPP
#define _DATABUS_CPP

#include "Databus.h"
#include "Processor.h"

Databus::Databus () {
	this->Content = 0;
	this->Busy = false;
	this->Corrupt = false;
}

Databus::~Databus () {

}

void Databus::setContent ( int content ) {
	if (this->Busy){
		this->Corrupt = true;
		throw CORRUPT_BIT_SET;
	}
	this->Content = content;
	this->Busy = true;
}

int Databus::getContent () {
	return this->Content & 255;
}

bool Databus::isBusy() {
	return this->Busy == true;
};

void Databus::setBusy() {
	this->Busy = true;
};

void Databus::resetBusy() {
	this->Busy = false;
};

void Databus::setBusy( bool busy ) {
	this->Busy = busy;
};

bool Databus::getBusy () {
	return this->Busy;
};

void Databus::resetCorrupt () {
	this->Corrupt = false;
}

#endif
