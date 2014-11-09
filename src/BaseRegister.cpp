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
#ifndef _BASE_REGISTER_CPP
#define _BASE_REGISTER_CPP

#include "BaseRegister.h"
#include "Processor.h"

Register::Register () {
	this->Content = 0;
	this->_nextContent = 0;
}

Register::~Register () {

}

void Register::setContent ( int content ) {
	this->_nextContent = content;
}

int Register::getContent () {
	return (int) this->Content & 0xFF;
}

void Register::clockPulse () {
	this->Content = this->_nextContent;
}

void Register::rightShift() {
	this->_nextContent = (this->_nextContent >> 1);
}

void Register::leftShift() {
	this->_nextContent = (this->_nextContent << 1);
}

void Register::increment() {
	this->_nextContent = (this->_nextContent + 1);
}

void Register::decrement() {
	this->_nextContent = (this->_nextContent - 1);
}

std::string Register::toString() {
	return std::to_string(this->Content);
}

#endif
