#ifndef _ALU_H
#define _ALU_H

class ALU
{
	private:
		int Flags;
	public:
		ALU();
		~ALU();

		void getContent(); // for pseudo-content

		void setFlags( int );
		int getFlags ();
};

#endif
