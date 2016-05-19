#ifndef _FLAG_H
#define _FLAG_H

#include "BaseRegister.h"
#include "IORF.h"

class Flag : public Register {
	private:
	public:
		Flag () {
			this->Content = 1;
			this->_nextContent = 1;
		}

		~Flag () {}

		bool getFlag(IO_RF* io) {
			switch(io->SFL) {
				case 0:
					return this->getU();
					break;
				case 1:
					return this->getZ();
					break;
				case 2:
					return this->getNZ();
					break;
				case 3:
					return this->getS();
					break;
				case 4:
					return this->getNS();
					break;
				case 5:
					return this->getC();
					break;
				case 6:
					return this->getNC();
					break;
				case 7:
					return this->getP();
					break;
			}
			return false; //Never goes here.
		}

		bool getU() {
			return (this->Content & 1) == 1; //Should Always Be 1.
		}

		void setZ() {
			this->Content = this->Content | 2;
		}

		void resetZ() {
			this->Content = this->Content & ~2;
		}

		void setZ( bool flag ) {
			if (flag)
				this->setZ();
			else
				this->resetZ();
		}

		bool getZ() {
			return ((this->Content >> 1) & 1) == 1;
		}

		void setNZ() {
			this->Content = this->Content | 4;
		}

		void resetNZ() {
			this->Content = this->Content & ~4;
		}

		void setNZ( bool flag ) {
			if (flag)
				this->setNZ();
			else
				this->resetNZ();
	 }

		bool getNZ() {
			return ((this->Content >> 2) & 1) == 1;
		}

		void setS() {
			this->Content = this->Content | 8;
		}

		void resetS() {
			this->Content = this->Content & ~8;
		}

		void setS( bool flag ) {
			if (flag)
				this->setS();
			else
				this->resetS();
		}

		bool getS() {
			return ((this->Content >> 3) & 1) == 1;
		}

		void setNS() {
			this->Content = this->Content | 16;
		}

		void resetNS() {
			this->Content = this->Content & ~16;
		}

		void setNS( bool flag ) {
			if (flag)
				this->setNS();
			else
				this->resetNS();
		}

		bool getNS() {
			return ((this->Content >> 4) & 1) == 1;
		}

		void setC() {
			this->Content = this->Content | 32;
		}

		void resetC() {
			this->Content = this->Content & ~32;
		}

		void setC( bool flag ) {
			if (flag)
				this->setC();
			else
				this->resetC();
		}

		bool getC() {
			return ((this->Content >> 5) & 1) == 1;
		}

		void setNC() {
			this->Content = this->Content | 64;
		}

		void resetNC() {
			this->Content = this->Content & ~64;
		}

		void setNC( bool flag ) {
			if (flag)
				this->setNC();
			else
				this->resetNC();
		}

		bool getNC() {
			return ((this->Content >> 6) & 1) == 1;
		}

		void setP() {
			this->Content = this->Content | 128;
		}

		void resetP() {
			this->Content = this->Content & ~128;
		}

		void setP( bool flag ) {
			if (flag)
				this->setP();
			else
				this->resetP();
		}

		bool getP() {
			return ((this->Content >> 7) & 1) == 1;
		}


		std::string toString()  {
			auto current = this->Content;
			std::string rv = "";
			for(int i=0;i<8;i++) {
				switch(i) {
					case 0:
						rv += "U :";
						break;
				  	case 1:
						rv += "Z :";
						break;
				 	case 2:
						rv += "NZ :";
						break;
				  	case 3:
						rv += "S :";
						break;
				  	case 4:
						rv += "NS :";
						break;
				  	case 5:
						rv += "C :";
						break;
					case 6:
						rv += "NC :";
						break;
					case 7:
						rv += "P :";
						break;
				}
				rv = rv + std::to_string((current>>i)&1) + "\t";
			}
			rv += '\n';
			return rv;
		}
};

#endif
