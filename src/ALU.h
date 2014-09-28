#ifndef _ALU_H
#define _ALU_H

class ALU
{
	private:
		int Content;
	public:
		ALU();
		~ALU();

		void setContent( int content );
		int getContent ( );
};

#endif
