#ifndef _STACKPOINTER_CPP
#define _STACKPOINTER_CPP

#include "StackPointer.h"
#include "Processor.h"

StackPointer::StackPointer () {
	this->Content = -1; // Becomes 255 on getContent()
}

StackPointer::~StackPointer () {

}

void StackPointer::processSignal () {
	if (microinstruction->ESP)
		databus->setContent(this->getContent());
	if (microinstruction->ISP)
		this->increment();
	if (microinstruction->DSP)
		this->decrement();
	if (microinstruction->LSP)
		this->setContent(databus->getContent());
}

#endif
