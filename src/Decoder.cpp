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
#ifndef _DECODER_CPP
#define _DECODER_CPP

#include "Decoder.h"
#include "Processor.h"

Decoder::Decoder () {
	this->hashTable.fill(0); //initially. 

	// @Ghosh : nop

	this->hashTable[ 0x00 ] = 2;

	this->hashTable[ 0x01 ] = 70; // @Ghosh : Parth says, "?!?!". 

	// @Ghosh : adi xx

	this->hashTable[ 0x02 ] = 3;

	// @Ghosh : sbi xx

	this->hashTable[ 0x03 ] = 5;

	// @Ghosh : xri xx

	this->hashTable[ 0x04 ] = 8;

	// @Ghosh : ani xx

	this->hashTable[ 0x05 ] = 11;

	// @Ghosh : ori xx

	this->hashTable[ 0x06 ] = 14;

	// @Ghosh : cmi xx

	this->hashTable[ 0x07 ] = 16;

	// @Ghosh : ret <fl>
	
	this->hashTable[ 0x08 ] = 19;
	this->hashTable[ 0x09 ] = 19;
	this->hashTable[ 0x0A ] = 19;
	this->hashTable[ 0x0B ] = 19;
	this->hashTable[ 0x0C ] = 19;
	this->hashTable[ 0x0D ] = 19;
	this->hashTable[ 0x0E ] = 19;
	this->hashTable[ 0x0F ] = 19;

	// @Ghosh : add <r>

	this->hashTable[ 0x10 ] = 22;
	this->hashTable[ 0x11 ] = 22;
	this->hashTable[ 0x12 ] = 22;
	this->hashTable[ 0x13 ] = 22;
	this->hashTable[ 0x14 ] = 22;
	this->hashTable[ 0x15 ] = 22;
	this->hashTable[ 0x16 ] = 22;
	this->hashTable[ 0x17 ] = 22;
	this->hashTable[ 0x18 ] = 22;
	this->hashTable[ 0x19 ] = 22;
	this->hashTable[ 0x1A ] = 22;
	this->hashTable[ 0x1B ] = 22;
	this->hashTable[ 0x1C ] = 22;
	this->hashTable[ 0x1D ] = 22;
	this->hashTable[ 0x1E ] = 22;
	this->hashTable[ 0x1F ] = 22;


	// @Ghosh : sub <r>

	this->hashTable[ 0x20 ] = 24;
	this->hashTable[ 0x21 ] = 24;
	this->hashTable[ 0x22 ] = 24;
	this->hashTable[ 0x23 ] = 24;
	this->hashTable[ 0x24 ] = 24;
	this->hashTable[ 0x25 ] = 24;
	this->hashTable[ 0x26 ] = 24;
	this->hashTable[ 0x27 ] = 24;
	this->hashTable[ 0x28 ] = 24;
	this->hashTable[ 0x29 ] = 24;
	this->hashTable[ 0x2A ] = 24;
	this->hashTable[ 0x2B ] = 24;
	this->hashTable[ 0x2C ] = 24;
	this->hashTable[ 0x2D ] = 24;
	this->hashTable[ 0x2E ] = 24;
	this->hashTable[ 0x2F ] = 24;

	// @Ghosh : xor <r>

	this->hashTable[ 0x30 ] = 26;
	this->hashTable[ 0x31 ] = 26;
	this->hashTable[ 0x32 ] = 26;
	this->hashTable[ 0x33 ] = 26;
	this->hashTable[ 0x34 ] = 26;
	this->hashTable[ 0x35 ] = 26;
	this->hashTable[ 0x36 ] = 26;
	this->hashTable[ 0x37 ] = 26;
	this->hashTable[ 0x38 ] = 26;
	this->hashTable[ 0x39 ] = 26;
	this->hashTable[ 0x3A ] = 26;
	this->hashTable[ 0x3B ] = 26;
	this->hashTable[ 0x3C ] = 26;
	this->hashTable[ 0x3D ] = 26;
	this->hashTable[ 0x3E ] = 26;
	this->hashTable[ 0x3F ] = 26;

	// @Ghosh : and <r>

	this->hashTable[ 0x40 ] = 28;
	this->hashTable[ 0x41 ] = 28;
	this->hashTable[ 0x42 ] = 28;
	this->hashTable[ 0x43 ] = 28;
	this->hashTable[ 0x44 ] = 28;
	this->hashTable[ 0x45 ] = 28;
	this->hashTable[ 0x46 ] = 28;
	this->hashTable[ 0x47 ] = 28;
	this->hashTable[ 0x48 ] = 28;
	this->hashTable[ 0x49 ] = 28;
	this->hashTable[ 0x4A ] = 28;
	this->hashTable[ 0x4B ] = 28;
	this->hashTable[ 0x4C ] = 28;
	this->hashTable[ 0x4D ] = 28;
	this->hashTable[ 0x4E ] = 28;
	this->hashTable[ 0x4F ] = 28;

	// @Ghosh : or <r>

	this->hashTable[ 0x50 ] = 30;
	this->hashTable[ 0x51 ] = 30;
	this->hashTable[ 0x52 ] = 30;
	this->hashTable[ 0x53 ] = 30;
	this->hashTable[ 0x54 ] = 30;
	this->hashTable[ 0x55 ] = 30;
	this->hashTable[ 0x56 ] = 30;
	this->hashTable[ 0x57 ] = 30;
	this->hashTable[ 0x58 ] = 30;
	this->hashTable[ 0x59 ] = 30;
	this->hashTable[ 0x5A ] = 30;
	this->hashTable[ 0x5B ] = 30;
	this->hashTable[ 0x5C ] = 30;
	this->hashTable[ 0x5D ] = 30;
	this->hashTable[ 0x5E ] = 30;
	this->hashTable[ 0x5F ] = 30;

	// @Ghosh : cmp <r>

	this->hashTable[ 0x60 ] = 32;
	this->hashTable[ 0x61 ] = 32;
	this->hashTable[ 0x62 ] = 32;
	this->hashTable[ 0x63 ] = 32;
	this->hashTable[ 0x64 ] = 32;
	this->hashTable[ 0x65 ] = 32;
	this->hashTable[ 0x66 ] = 32;
	this->hashTable[ 0x67 ] = 32;
	this->hashTable[ 0x68 ] = 32;
	this->hashTable[ 0x69 ] = 32;
	this->hashTable[ 0x6A ] = 32;
	this->hashTable[ 0x6B ] = 32;
	this->hashTable[ 0x6C ] = 32;
	this->hashTable[ 0x6D ] = 32;
	this->hashTable[ 0x6E ] = 32;
	this->hashTable[ 0x6F ] = 32;

	// @Ghosh : movs <r>

	this->hashTable[ 0x70 ] = 34;
	this->hashTable[ 0x71 ] = 34;
	this->hashTable[ 0x72 ] = 34;
	this->hashTable[ 0x73 ] = 34;
	this->hashTable[ 0x74 ] = 34;
	this->hashTable[ 0x75 ] = 34;
	this->hashTable[ 0x76 ] = 34;
	this->hashTable[ 0x77 ] = 34;
	this->hashTable[ 0x78 ] = 34;
	this->hashTable[ 0x79 ] = 34;
	this->hashTable[ 0x7A ] = 34;
	this->hashTable[ 0x7B ] = 34;
	this->hashTable[ 0x7C ] = 34;
	this->hashTable[ 0x7D ] = 34;
	this->hashTable[ 0x7E ] = 34;
	this->hashTable[ 0x7F ] = 34;

	// @Ghosh : movd <r>

	this->hashTable[ 0x80 ] = 35;
	this->hashTable[ 0x81 ] = 35;
	this->hashTable[ 0x82 ] = 35;
	this->hashTable[ 0x83 ] = 35;
	this->hashTable[ 0x84 ] = 35;
	this->hashTable[ 0x85 ] = 35;
	this->hashTable[ 0x86 ] = 35;
	this->hashTable[ 0x87 ] = 35;
	this->hashTable[ 0x88 ] = 35;
	this->hashTable[ 0x89 ] = 35;
	this->hashTable[ 0x8A ] = 35;
	this->hashTable[ 0x8B ] = 35;
	this->hashTable[ 0x8C ] = 35;
	this->hashTable[ 0x8D ] = 35;
	this->hashTable[ 0x8E ] = 35;
	this->hashTable[ 0x8F ] = 35;

	// @Ghosh : movi <r> xx

	this->hashTable[ 0x90 ] = 36;
	this->hashTable[ 0x91 ] = 36;
	this->hashTable[ 0x92 ] = 36;
	this->hashTable[ 0x93 ] = 36;
	this->hashTable[ 0x94 ] = 36;
	this->hashTable[ 0x95 ] = 36;
	this->hashTable[ 0x96 ] = 36;
	this->hashTable[ 0x97 ] = 36;
	this->hashTable[ 0x98 ] = 36;
	this->hashTable[ 0x99 ] = 36;
	this->hashTable[ 0x9A ] = 36;
	this->hashTable[ 0x9B ] = 36;
	this->hashTable[ 0x9C ] = 36;
	this->hashTable[ 0x9D ] = 36;
	this->hashTable[ 0x9E ] = 36;
	this->hashTable[ 0x9F ] = 36;

	// @Ghosh : stor <r> 

	this->hashTable[ 0xA0 ] = 38;
	this->hashTable[ 0xA1 ] = 38;
	this->hashTable[ 0xA2 ] = 38;
	this->hashTable[ 0xA3 ] = 38;
	this->hashTable[ 0xA4 ] = 38;
	this->hashTable[ 0xA5 ] = 38;
	this->hashTable[ 0xA6 ] = 38;
	this->hashTable[ 0xA7 ] = 38;
	this->hashTable[ 0xA8 ] = 38;
	this->hashTable[ 0xA9 ] = 38;
	this->hashTable[ 0xAA ] = 38;
	this->hashTable[ 0xAB ] = 38;
	this->hashTable[ 0xAC ] = 38;
	this->hashTable[ 0xAD ] = 38;
	this->hashTable[ 0xAE ] = 38;
	this->hashTable[ 0xAF ] = 38;

	// @Ghosh : load <r>

	this->hashTable[ 0xB0 ] = 40;
	this->hashTable[ 0xB1 ] = 40;
	this->hashTable[ 0xB2 ] = 40;
	this->hashTable[ 0xB3 ] = 40;
	this->hashTable[ 0xB4 ] = 40;
	this->hashTable[ 0xB5 ] = 40;
	this->hashTable[ 0xB6 ] = 40;
	this->hashTable[ 0xB7 ] = 40;
	this->hashTable[ 0xB8 ] = 40;
	this->hashTable[ 0xB9 ] = 40;
	this->hashTable[ 0xBA ] = 40;
	this->hashTable[ 0xBB ] = 40;
	this->hashTable[ 0xBC ] = 40;
	this->hashTable[ 0xBD ] = 40;
	this->hashTable[ 0xBE ] = 40;
	this->hashTable[ 0xBF ] = 40;

	// @Ghosh : push <r>

	this->hashTable[ 0xC0 ] = 42;
	this->hashTable[ 0xC1 ] = 42;
	this->hashTable[ 0xC2 ] = 42;
	this->hashTable[ 0xC3 ] = 42;
	this->hashTable[ 0xC4 ] = 42;
	this->hashTable[ 0xC5 ] = 42;
	this->hashTable[ 0xC6 ] = 42;
	this->hashTable[ 0xC7 ] = 42;
	this->hashTable[ 0xC8 ] = 42;
	this->hashTable[ 0xC9 ] = 42;
	this->hashTable[ 0xCA ] = 42;
	this->hashTable[ 0xCB ] = 42;
	this->hashTable[ 0xCC ] = 42;
	this->hashTable[ 0xCD ] = 42;
	this->hashTable[ 0xCE ] = 42;
	this->hashTable[ 0xCF ] = 42;

	// @Ghosh : pop <r>

	this->hashTable[ 0xD0 ] = 45;
	this->hashTable[ 0xD1 ] = 45;
	this->hashTable[ 0xD2 ] = 45;
	this->hashTable[ 0xD3 ] = 45;
	this->hashTable[ 0xD4 ] = 45;
	this->hashTable[ 0xD5 ] = 45;
	this->hashTable[ 0xD6 ] = 45;
	this->hashTable[ 0xD7 ] = 45;
	this->hashTable[ 0xD8 ] = 45;
	this->hashTable[ 0xD9 ] = 45;
	this->hashTable[ 0xDA ] = 45;
	this->hashTable[ 0xDB ] = 45;
	this->hashTable[ 0xDC ] = 45;
	this->hashTable[ 0xDD ] = 45;
	this->hashTable[ 0xDE ] = 45;
	this->hashTable[ 0xDF ] = 45;

	// @Ghosh : jumpd <fl> xx

	this->hashTable[ 0xE0 ] = 47;
	this->hashTable[ 0xE1 ] = 47;
	this->hashTable[ 0xE2 ] = 47;
	this->hashTable[ 0xE3 ] = 47;
	this->hashTable[ 0xE4 ] = 47;
	this->hashTable[ 0xE5 ] = 47;
	this->hashTable[ 0xE6 ] = 47;
	this->hashTable[ 0xE7 ] = 47;

	// @Ghosh : jmpr <fl>

	this->hashTable[ 0xE8 ] = 49;
	this->hashTable[ 0xE9 ] = 49;
	this->hashTable[ 0xEA ] = 49;
	this->hashTable[ 0xEB ] = 49;
	this->hashTable[ 0xEC ] = 49;
	this->hashTable[ 0xED ] = 49;
	this->hashTable[ 0xEE ] = 49;
	this->hashTable[ 0xEF ] = 49;

	// @Ghosh : cd <fl> xx

	this->hashTable[ 0xF0 ] = 51;
	this->hashTable[ 0xF1 ] = 51;
	this->hashTable[ 0xF2 ] = 51;
	this->hashTable[ 0xF3 ] = 51;
	this->hashTable[ 0xF4 ] = 51;
	this->hashTable[ 0xF5 ] = 51;
	this->hashTable[ 0xF6 ] = 51;
	this->hashTable[ 0xF7 ] = 51;	

	// @Ghosh : cr <fl> 

	this->hashTable[ 0xF8 ] = 56;
	this->hashTable[ 0xF9 ] = 56;
	this->hashTable[ 0xFA ] = 56;
	this->hashTable[ 0xFB ] = 56;
	this->hashTable[ 0xFC ] = 56;
	this->hashTable[ 0xFD ] = 56;
	this->hashTable[ 0xFE ] = 56;
	this->hashTable[ 0xFF ] = 56;
}

Decoder::~Decoder () {

}

int Decoder::getContent() {
	return this->hashTable[ instruction->getContent() ];
}

Decoder::Decoder (std::string path) {

}

Decoder::Decoder (std::fstream infile) {

}

Decoder::Decoder (std::ifstream infile) {

}

#endif
