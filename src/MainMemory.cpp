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
	return (int) this->mainMemory [ memoryAddress->getContent() ];
}

#endif
