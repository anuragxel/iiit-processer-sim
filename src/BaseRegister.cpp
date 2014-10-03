#ifndef _BASE_REGISTER_CPP
#define _BASE_REGISTER_CPP

#include "BaseRegister.h"
#include "Processor.h"

Register::Register () {
	this->Content = 0;
	this->_previousContent = 0;
}

Register::~Register () {

}

void Register::setContent ( int content ) {
	this->_previousContent = content;
}

int Register::getContent () {
	return this->Content & 255;
}

void Register::clockPulse () {
	this->Content = this->_previousContent;
}

void Register::rightShift() {
	this->_previousContent = (this->_previousContent >> 1);
}

void Register::leftShift() {
	this->_previousContent = (this->_previousContent << 1);
}

void Register::increment() {
	this->_previousContent = (this->_previousContent + 1);
}

void Register::decrement() {
	this->_previousContent = (this->_previousContent - 1);
}

#endif
