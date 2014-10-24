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
#ifndef _FLAG_CPP
#define _FLAG_CPP

#include "Flag.h"
#include "Processor.h"

Flag::Flag () {
	this->Content = 1;
}

Flag::~Flag () {

}

bool Flag::getFlag() {
	switch(io->SFL)
	{
		case 0:
			return this->getU();
			break;
		case 1:
			return this->getZ();
			break;
		case 2:
			return this->getNZ();
			break;
		case 3:
			return this->getS();
			break;
		case 4:
			return this->getNS();
			break;
		case 5:
			return this->getC();
			break;
		case 6:
			return this->getNC();
			break;
		case 7:
			return this->getP();
			break;
	}
	return false; //Never goes here.
}

void Flag::processSignal () {
	if (microinstruction->EFL)
		microinstruction->RMS = true; // @Ghosh : This will reset MS when Flag is not 0, according to logic defined in <MS>.cpp
	// @Ghosh : |-> If EFL then set RMS true. RMS will actually reset if EFL && !getFlag(). So it is safe. 
	// @Ghosh : |-> (END -> RMS) logic still applies here. Since rule defined in <MS>.cpp
}

void StackPointer::processSignalUpwardEdge(){

}

void StackPointer::processSignalDownwardEdge(){
	
}

bool Flag::getU() {
	return (this->Content & 1) == 1; //Should Always Be 1.
}

void Flag::setZ() {
	this->Content = this->Content | 2;
}

void Flag::resetZ() {
	this->Content = this->Content & ~2;
}

void Flag::setZ( bool flag ) {
	if (flag)
		this->setZ();
	else
		this->resetZ();
}

bool Flag::getZ() {
	return ((this->Content >> 1) & 1) == 1;
}

void Flag::setNZ() {
	this->Content = this->Content | 4;
}

void Flag::resetNZ() {
	this->Content = this->Content & ~4;
}

void Flag::setNZ( bool flag ) {
	if (flag)
		this->setNZ();
	else
		this->resetNZ();
}

bool Flag::getNZ() {
	return ((this->Content >> 2) & 1) == 1;
}

void Flag::setS() {
	this->Content = this->Content | 8;
}

void Flag::resetS() {
	this->Content = this->Content & ~8;
}

void Flag::setS( bool flag ) {
	if (flag)
		this->setS();
	else
		this->resetS();
}

bool Flag::getS() {
	return ((this->Content >> 3) & 1) == 1;
}

void Flag::setNS() {
	this->Content = this->Content | 16;
}

void Flag::resetNS() {
	this->Content = this->Content & ~16;
}

void Flag::setNS( bool flag ) {
	if (flag)
		this->setNS();
	else
		this->resetNS();
}

bool Flag::getNS() {
	return ((this->Content >> 4) & 1) == 1;
}

void Flag::setC() {
	this->Content = this->Content | 32;
}

void Flag::resetC() {
	this->Content = this->Content & ~32;
}

void Flag::setC( bool flag ) {
	if (flag)
		this->setC();
	else
		this->resetC();
}

bool Flag::getC() {
	return ((this->Content >> 5) & 1) == 1;
}

void Flag::setNC() {
	this->Content = this->Content | 64;
}

void Flag::resetNC() {
	this->Content = this->Content & ~64;
}

void Flag::setNC( bool flag ) {
	if (flag)
		this->setNC();
	else
		this->resetNC();
}

bool Flag::getNC() {
	return ((this->Content >> 6) & 1) == 1;
}

void Flag::setP() {
	this->Content = this->Content | 128;
}

void Flag::resetP() {
	this->Content = this->Content & ~128;
}

void Flag::setP( bool flag ) {
	if (flag)
		this->setP();
	else
		this->resetP();
}

bool Flag::getP() {
	return ((this->Content >> 7) & 1) == 1;
}

#endif
