#ifndef _DATABUS_H
#define _DATABUS_H

class Databus
{
	private:
		int Content;
		bool flag;
	public:
		Databus();
		~Databus();

		void setContent( int );
		int getContent ( );

		bool isBusy();
		bool setBusy();
		bool resetBusy();

		void setBusy( bool );
		bool getBusy ();
};

#endif
