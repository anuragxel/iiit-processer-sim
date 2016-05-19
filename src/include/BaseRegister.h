#ifndef _BASE_REGISTER_H
#define _BASE_REGISTER_H

#include <string>

class Register
{
	protected:
		int Content;
		int _nextContent;
	public:
		Register() {
			this->Content = 0;
			this->_nextContent = 0;
		}

		~Register() {}

		void setContent(int content) {
			this->_nextContent = content;
		}
		int getContent () {
			return (int) this->Content & 0xFF;
		}
		void clockPulse() {
			this->Content = this->_nextContent;
		}

		//Register Level Capablities. Not exploited by Processor, but included just in case.
		void rightShift() {
			this->_nextContent = (this->_nextContent >> 1);
		}
		void leftShift() {
			this->_nextContent = (this->_nextContent << 1);
		}
		void increment() {
			this->_nextContent = (this->_nextContent + 1);
		}
		void decrement() {
			this->_nextContent = (this->_nextContent - 1);
		}
		std::string toString() {
			if(this->Content == 0) {
				return " ";
			}
			return std::to_string(this->Content);
		}
};

#endif
