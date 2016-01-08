#ifndef _BASE_REGISTER_CPP
#define _BASE_REGISTER_CPP

#include "include/BaseRegister.h"
#include "include/Processor.h"

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
