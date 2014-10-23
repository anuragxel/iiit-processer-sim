/*
 * This file is part of Std-Arch-Sim.
 *
 * Std-Arch-Sim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Std-Arch-Sim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Std-Arch-Sim.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _FLAG_H
#define _FLAG_H

#include "BaseRegister.h"

class Flag : public Register {
	private:
	public:
		Flag();
		~Flag();

		bool getFlag(); //get for pseudo variable Flag

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
