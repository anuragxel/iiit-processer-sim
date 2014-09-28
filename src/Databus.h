#ifndef _DATABUS_H
#define _DATABUS_H

class Databus
{
	private:
		int Content;
	public:
		Databus();
		~Databus();

		void setContent( int content );
		int getContent ( );
};

#endif
