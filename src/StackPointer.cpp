#ifndef _STACKPOINTER_CPP
#define _STACKPOINTER_CPP

#include "include/StackPointer.h"
#include "include/Processor.h"

StackPointer::StackPointer () {
	this->Content = -1; // Becomes 255 on getContent()
}

StackPointer::~StackPointer () {

}

void StackPointer::processSignalRisingEdge(){
	if (microinstruction->ESP) {
		std::cout << "ESP\t";
		databus->setContent(this->getContent());
	}
}

void StackPointer::processSignalFallingEdge(){
	if (microinstruction->ISP) {
		std::cout << "ISP\t";
		this->increment();
	}
	if (microinstruction->DSP) {
		std::cout << "DSP\t";
		this->decrement();
	}
	if (microinstruction->LSP) {
		std::cout << "LSP\t";
		this->setContent(databus->getContent());
	}
}

#endif
