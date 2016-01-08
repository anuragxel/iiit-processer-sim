#ifndef _BASE_REGISTER_H
#define _BASE_REGISTER_H

#include <string>

class Register
{
	protected:
		int Content;
		int _nextContent;
	public:
		Register();
		~Register();

		void setContent( int content );
		int getContent ();
		void clockPulse();

		//Register Level Capablities. Not exploited by Processor, but included just in case.
		void rightShift();
		void leftShift();
		void increment();
		void decrement();
		std::string toString();
};

#endif
