#ifndef _ACCUMULATOR_H
#define _ACCUMULATOR_H

class Accumulator
{
	private:
		int Content;
	public:
		Accumulator();
		~Accumulator();

		void setContent( int content );
		int getContent ( );
};

#endif
