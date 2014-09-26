#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

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
