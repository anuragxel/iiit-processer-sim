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
#ifndef _MAINMEMORY_CPP
#define _MAINMEMORY_CPP

#include "MainMemory.h"
#include "Processor.h"

MainMemory::MainMemory () {
	this->mainMemory.fill(0);
}

MainMemory::~MainMemory () {

}

MainMemory::MainMemory (std::string path) {
	std::ifstream infile;
	infile.open(path , std::ios::binary);
	if (!infile)
		throw FILE_NOT_READABLE;
	infile.read(this->mainMemory.data() , sizeof(mainMemory));
	infile.close();
}

MainMemory::MainMemory (std::fstream infile) {
	if (!infile.is_open())
		throw INVALID_STREAM;
	infile.read(this->mainMemory.data() , sizeof(mainMemory));
	infile.close();
}

MainMemory::MainMemory (std::ifstream infile) {
	if (!infile.is_open())
		throw INVALID_STREAM;
	infile.read(this->mainMemory.data() , sizeof(mainMemory));
	infile.close();
}

void MainMemory::setContent ( int content ) {
	this->mainMemory[ memoryAddress->getContent() ] = (char) content;
}

int MainMemory::getContent () {
	return (int) ((this->mainMemory [ memoryAddress->getContent() ]) & 0xFF);
}

#endif
