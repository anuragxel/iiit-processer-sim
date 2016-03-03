#ifndef _DECODER_CPP
#define _DECODER_CPP

#include "include/Decoder.h"
#include "include/Processor.h"

Decoder::Decoder () {
	this->hashTable.fill(0); //initially.

	// @Ghosh : nop

	this->hashTable[ 0x00 ] = 2;

	this->hashTable[ 0x01 ] = 70; // @Ghosh : Parth says, "?!?!".

	// @Ghosh : adi xx

	this->hashTable[ 0x02 ] = 3;

	// @Ghosh : sbi xx

	this->hashTable[ 0x03 ] = 6;

	// @Ghosh : xri xx

	this->hashTable[ 0x04 ] = 9;

	// @Ghosh : ani xx

	this->hashTable[ 0x05 ] = 12;

	// @Ghosh : ori xx

	this->hashTable[ 0x06 ] = 15;

	// @Ghosh : cmi xx

	this->hashTable[ 0x07 ] = 18;

	// @Ghosh : ret <fl>

	this->hashTable[ 0x08 ] = 21;
	this->hashTable[ 0x09 ] = 21;
	this->hashTable[ 0x0A ] = 21;
	this->hashTable[ 0x0B ] = 21;
	this->hashTable[ 0x0C ] = 21;
	this->hashTable[ 0x0D ] = 21;
	this->hashTable[ 0x0E ] = 21;
	this->hashTable[ 0x0F ] = 21;

	// @Ghosh : add <r>

	this->hashTable[ 0x10 ] = 24;
	this->hashTable[ 0x11 ] = 24;
	this->hashTable[ 0x12 ] = 24;
	this->hashTable[ 0x13 ] = 24;
	this->hashTable[ 0x14 ] = 24;
	this->hashTable[ 0x15 ] = 24;
	this->hashTable[ 0x16 ] = 24;
	this->hashTable[ 0x17 ] = 24;
	this->hashTable[ 0x18 ] = 24;
	this->hashTable[ 0x19 ] = 24;
	this->hashTable[ 0x1A ] = 24;
	this->hashTable[ 0x1B ] = 24;
	this->hashTable[ 0x1C ] = 24;
	this->hashTable[ 0x1D ] = 24;
	this->hashTable[ 0x1E ] = 24;
	this->hashTable[ 0x1F ] = 24;


	// @Ghosh : sub <r>

	this->hashTable[ 0x20 ] = 26;
	this->hashTable[ 0x21 ] = 26;
	this->hashTable[ 0x22 ] = 26;
	this->hashTable[ 0x23 ] = 26;
	this->hashTable[ 0x24 ] = 26;
	this->hashTable[ 0x25 ] = 26;
	this->hashTable[ 0x26 ] = 26;
	this->hashTable[ 0x27 ] = 26;
	this->hashTable[ 0x28 ] = 26;
	this->hashTable[ 0x29 ] = 26;
	this->hashTable[ 0x2A ] = 26;
	this->hashTable[ 0x2B ] = 26;
	this->hashTable[ 0x2C ] = 26;
	this->hashTable[ 0x2D ] = 26;
	this->hashTable[ 0x2E ] = 26;
	this->hashTable[ 0x2F ] = 26;

	// @Ghosh : xor <r>

	this->hashTable[ 0x30 ] = 28;
	this->hashTable[ 0x31 ] = 28;
	this->hashTable[ 0x32 ] = 28;
	this->hashTable[ 0x33 ] = 28;
	this->hashTable[ 0x34 ] = 28;
	this->hashTable[ 0x35 ] = 28;
	this->hashTable[ 0x36 ] = 28;
	this->hashTable[ 0x37 ] = 28;
	this->hashTable[ 0x38 ] = 28;
	this->hashTable[ 0x39 ] = 28;
	this->hashTable[ 0x3A ] = 28;
	this->hashTable[ 0x3B ] = 28;
	this->hashTable[ 0x3C ] = 28;
	this->hashTable[ 0x3D ] = 28;
	this->hashTable[ 0x3E ] = 28;
	this->hashTable[ 0x3F ] = 28;

	// @Ghosh : and <r>

	this->hashTable[ 0x40 ] = 30;
	this->hashTable[ 0x41 ] = 30;
	this->hashTable[ 0x42 ] = 30;
	this->hashTable[ 0x43 ] = 30;
	this->hashTable[ 0x44 ] = 30;
	this->hashTable[ 0x45 ] = 30;
	this->hashTable[ 0x46 ] = 30;
	this->hashTable[ 0x47 ] = 30;
	this->hashTable[ 0x48 ] = 30;
	this->hashTable[ 0x49 ] = 30;
	this->hashTable[ 0x4A ] = 30;
	this->hashTable[ 0x4B ] = 30;
	this->hashTable[ 0x4C ] = 30;
	this->hashTable[ 0x4D ] = 30;
	this->hashTable[ 0x4E ] = 30;
	this->hashTable[ 0x4F ] = 30;

	// @Ghosh : or <r>

	this->hashTable[ 0x50 ] = 32;
	this->hashTable[ 0x51 ] = 32;
	this->hashTable[ 0x52 ] = 32;
	this->hashTable[ 0x53 ] = 32;
	this->hashTable[ 0x54 ] = 32;
	this->hashTable[ 0x55 ] = 32;
	this->hashTable[ 0x56 ] = 32;
	this->hashTable[ 0x57 ] = 32;
	this->hashTable[ 0x58 ] = 32;
	this->hashTable[ 0x59 ] = 32;
	this->hashTable[ 0x5A ] = 32;
	this->hashTable[ 0x5B ] = 32;
	this->hashTable[ 0x5C ] = 32;
	this->hashTable[ 0x5D ] = 32;
	this->hashTable[ 0x5E ] = 32;
	this->hashTable[ 0x5F ] = 32;

	// @Ghosh : cmp <r>

	this->hashTable[ 0x60 ] = 34;
	this->hashTable[ 0x61 ] = 34;
	this->hashTable[ 0x62 ] = 34;
	this->hashTable[ 0x63 ] = 34;
	this->hashTable[ 0x64 ] = 34;
	this->hashTable[ 0x65 ] = 34;
	this->hashTable[ 0x66 ] = 34;
	this->hashTable[ 0x67 ] = 34;
	this->hashTable[ 0x68 ] = 34;
	this->hashTable[ 0x69 ] = 34;
	this->hashTable[ 0x6A ] = 34;
	this->hashTable[ 0x6B ] = 34;
	this->hashTable[ 0x6C ] = 34;
	this->hashTable[ 0x6D ] = 34;
	this->hashTable[ 0x6E ] = 34;
	this->hashTable[ 0x6F ] = 34;

	// @Ghosh : movs <r>

	this->hashTable[ 0x70 ] = 36;
	this->hashTable[ 0x71 ] = 36;
	this->hashTable[ 0x72 ] = 36;
	this->hashTable[ 0x73 ] = 36;
	this->hashTable[ 0x74 ] = 36;
	this->hashTable[ 0x75 ] = 36;
	this->hashTable[ 0x76 ] = 36;
	this->hashTable[ 0x77 ] = 36;
	this->hashTable[ 0x78 ] = 36;
	this->hashTable[ 0x79 ] = 36;
	this->hashTable[ 0x7A ] = 36;
	this->hashTable[ 0x7B ] = 36;
	this->hashTable[ 0x7C ] = 36;
	this->hashTable[ 0x7D ] = 36;
	this->hashTable[ 0x7E ] = 36;
	this->hashTable[ 0x7F ] = 36;

	// @Ghosh : movd <r>

	this->hashTable[ 0x80 ] = 37;
	this->hashTable[ 0x81 ] = 37;
	this->hashTable[ 0x82 ] = 37;
	this->hashTable[ 0x83 ] = 37;
	this->hashTable[ 0x84 ] = 37;
	this->hashTable[ 0x85 ] = 37;
	this->hashTable[ 0x86 ] = 37;
	this->hashTable[ 0x87 ] = 37;
	this->hashTable[ 0x88 ] = 37;
	this->hashTable[ 0x89 ] = 37;
	this->hashTable[ 0x8A ] = 37;
	this->hashTable[ 0x8B ] = 37;
	this->hashTable[ 0x8C ] = 37;
	this->hashTable[ 0x8D ] = 37;
	this->hashTable[ 0x8E ] = 37;
	this->hashTable[ 0x8F ] = 37;

	// @Ghosh : movi <r> xx

	this->hashTable[ 0x90 ] = 38;
	this->hashTable[ 0x91 ] = 38;
	this->hashTable[ 0x92 ] = 38;
	this->hashTable[ 0x93 ] = 38;
	this->hashTable[ 0x94 ] = 38;
	this->hashTable[ 0x95 ] = 38;
	this->hashTable[ 0x96 ] = 38;
	this->hashTable[ 0x97 ] = 38;
	this->hashTable[ 0x98 ] = 38;
	this->hashTable[ 0x99 ] = 38;
	this->hashTable[ 0x9A ] = 38;
	this->hashTable[ 0x9B ] = 38;
	this->hashTable[ 0x9C ] = 38;
	this->hashTable[ 0x9D ] = 38;
	this->hashTable[ 0x9E ] = 38;
	this->hashTable[ 0x9F ] = 38;

	// @Ghosh : stor <r>

	this->hashTable[ 0xA0 ] = 40;
	this->hashTable[ 0xA1 ] = 40;
	this->hashTable[ 0xA2 ] = 40;
	this->hashTable[ 0xA3 ] = 40;
	this->hashTable[ 0xA4 ] = 40;
	this->hashTable[ 0xA5 ] = 40;
	this->hashTable[ 0xA6 ] = 40;
	this->hashTable[ 0xA7 ] = 40;
	this->hashTable[ 0xA8 ] = 40;
	this->hashTable[ 0xA9 ] = 40;
	this->hashTable[ 0xAA ] = 40;
	this->hashTable[ 0xAB ] = 40;
	this->hashTable[ 0xAC ] = 40;
	this->hashTable[ 0xAD ] = 40;
	this->hashTable[ 0xAE ] = 40;
	this->hashTable[ 0xAF ] = 40;

	// @Ghosh : load <r>

	this->hashTable[ 0xB0 ] = 42;
	this->hashTable[ 0xB1 ] = 42;
	this->hashTable[ 0xB2 ] = 42;
	this->hashTable[ 0xB3 ] = 42;
	this->hashTable[ 0xB4 ] = 42;
	this->hashTable[ 0xB5 ] = 42;
	this->hashTable[ 0xB6 ] = 42;
	this->hashTable[ 0xB7 ] = 42;
	this->hashTable[ 0xB8 ] = 42;
	this->hashTable[ 0xB9 ] = 42;
	this->hashTable[ 0xBA ] = 42;
	this->hashTable[ 0xBB ] = 42;
	this->hashTable[ 0xBC ] = 42;
	this->hashTable[ 0xBD ] = 42;
	this->hashTable[ 0xBE ] = 42;
	this->hashTable[ 0xBF ] = 42;

	// @Ghosh : push <r>

	this->hashTable[ 0xC0 ] = 44;
	this->hashTable[ 0xC1 ] = 44;
	this->hashTable[ 0xC2 ] = 44;
	this->hashTable[ 0xC3 ] = 44;
	this->hashTable[ 0xC4 ] = 44;
	this->hashTable[ 0xC5 ] = 44;
	this->hashTable[ 0xC6 ] = 44;
	this->hashTable[ 0xC7 ] = 44;
	this->hashTable[ 0xC8 ] = 44;
	this->hashTable[ 0xC9 ] = 44;
	this->hashTable[ 0xCA ] = 44;
	this->hashTable[ 0xCB ] = 44;
	this->hashTable[ 0xCC ] = 44;
	this->hashTable[ 0xCD ] = 44;
	this->hashTable[ 0xCE ] = 44;
	this->hashTable[ 0xCF ] = 44;

	// @Ghosh : pop <r>

	this->hashTable[ 0xD0 ] = 47;
	this->hashTable[ 0xD1 ] = 47;
	this->hashTable[ 0xD2 ] = 47;
	this->hashTable[ 0xD3 ] = 47;
	this->hashTable[ 0xD4 ] = 47;
	this->hashTable[ 0xD5 ] = 47;
	this->hashTable[ 0xD6 ] = 47;
	this->hashTable[ 0xD7 ] = 47;
	this->hashTable[ 0xD8 ] = 47;
	this->hashTable[ 0xD9 ] = 47;
	this->hashTable[ 0xDA ] = 47;
	this->hashTable[ 0xDB ] = 47;
	this->hashTable[ 0xDC ] = 47;
	this->hashTable[ 0xDD ] = 47;
	this->hashTable[ 0xDE ] = 47;
	this->hashTable[ 0xDF ] = 47;

	// @Ghosh : jumpd <fl> xx

	this->hashTable[ 0xE0 ] = 49;
	this->hashTable[ 0xE1 ] = 49;
	this->hashTable[ 0xE2 ] = 49;
	this->hashTable[ 0xE3 ] = 49;
	this->hashTable[ 0xE4 ] = 49;
	this->hashTable[ 0xE5 ] = 49;
	this->hashTable[ 0xE6 ] = 49;
	this->hashTable[ 0xE7 ] = 49;

	// @Ghosh : jmpr <fl>

	this->hashTable[ 0xE8 ] = 51;
	this->hashTable[ 0xE9 ] = 51;
	this->hashTable[ 0xEA ] = 51;
	this->hashTable[ 0xEB ] = 51;
	this->hashTable[ 0xEC ] = 51;
	this->hashTable[ 0xED ] = 51;
	this->hashTable[ 0xEE ] = 51;
	this->hashTable[ 0xEF ] = 51;

	// @Ghosh : cd <fl> xx

	this->hashTable[ 0xF0 ] = 53;
	this->hashTable[ 0xF1 ] = 53;
	this->hashTable[ 0xF2 ] = 53;
	this->hashTable[ 0xF3 ] = 53;
	this->hashTable[ 0xF4 ] = 53;
	this->hashTable[ 0xF5 ] = 53;
	this->hashTable[ 0xF6 ] = 53;
	this->hashTable[ 0xF7 ] = 53;

	// @Ghosh : cr <fl>

	this->hashTable[ 0xF8 ] = 58;
	this->hashTable[ 0xF9 ] = 58;
	this->hashTable[ 0xFA ] = 58;
	this->hashTable[ 0xFB ] = 58;
	this->hashTable[ 0xFC ] = 58;
	this->hashTable[ 0xFD ] = 58;
	this->hashTable[ 0xFE ] = 58;
	this->hashTable[ 0xFF ] = 58;
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
