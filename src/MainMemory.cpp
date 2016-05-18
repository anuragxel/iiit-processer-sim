#ifndef _MAINMEMORY_CPP
#define _MAINMEMORY_CPP

#include "include/MainMemory.h"
#include "include/Processor.h"

MainMemory::MainMemory () {
	this->mainMemory.fill(0); // Un-necessary by implementation of g++, this will be done automatically. But other compilers will complain.
									// g++ optimises it away anyways. :P. All hail g++. All hail Stallman. GNU FTW!.
	this->mainMemory[255] = 0x01; //STOP
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
	this->mainMemory[255] = 0x01;
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

void MainMemory::manualEdit (int index, int content) {
	this->mainMemory[ index & 0xFF ] = (char) content;
}

void MainMemory::setContent (int content) {
	this->mainMemory[ memoryAddress->getContent() ] = (char) content;
}

int MainMemory::getContent () {
	return (int) ((this->mainMemory [ memoryAddress->getContent() ]) & 0xFF);
}

void MainMemory::processSignalRisingEdge (){
	if(microinstruction->RD) {
		std::cout << "RD\t";
		databus->setContent(this->getContent());
	}
}

void MainMemory::processSignalFallingEdge (){
	if(microinstruction->WR) {
		std::cout << "WR\t";
		this->setContent(databus->getContent());
	}
}

template< typename T >std::string hexed(T a) {
	std::stringstream stream;
	stream << std::hex << a;
	return stream.str();
}

std::string MainMemory::toString() {
	std::string buffer;
	buffer = "M |";
	for(int i=0;i<16;i++) {
		buffer += "\t" + hexed(i);
	}
	buffer += "\n\n0 |\t";
	for(int i=0;i<256;i++) {
		buffer += hexed((unsigned int)(this->mainMemory[i] & 0xFF)) + "\t";
		if(!((i+1)%16) && (i+1)/16 != 16) {
			buffer +="\n" + hexed((i+1)/16) + " |\t";
		}
	}
	return buffer;
}

#endif
