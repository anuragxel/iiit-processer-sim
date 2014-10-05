#ifndef _FLAG_H
#define _FLAG_H

#include "BaseRegister.h"

class Flag : public Register {
	private:
	public:
		Flag();
		~Flag();

		bool getU();

		void setZ();
		void resetZ();
		void setZ( bool );
		bool getZ();

		void setNZ();
		void resetNZ();
		void setNZ( bool );
		bool getNZ();

		void setS();
		void resetS();
		void setS( bool );
		bool getS();

		void setNS();
		void resetNS();
		void setNS( bool );
		bool getNS();

		void setC();
		void resetC();
		void setC( bool );
		bool getC();

		void setNC();
		void resetNC();
		void setNC( bool );
		bool getNC();

		void setP();
		void resetP();
		void setP( bool );
		bool getP();

		void processSignal();
};

#endif
