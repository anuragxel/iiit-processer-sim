#ifndef _DATABUS_H
#define _DATABUS_H

class Databus
{
	private:
		int Content;
		bool Busy;
		bool Corrupt;
	public:
		Databus();
		~Databus();

		void setContent( int );
		int getContent ( );

		bool isBusy();
		void setBusy();
		void resetBusy();

		void setBusy( bool );
		bool getBusy ();

		void resetCorrupt();
};

#endif
