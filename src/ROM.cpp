#ifndef _ROM_CPP
#define _ROM_CPP

#include "include/ROM.h"
#include "include/Processor.h"


//
// PARTH ------------- I WANNA KILL U :P
//
ROM::ROM () {
	this->hashTable.resize(64); // Will call the constructor for default values of <Microinstruction> which happens to be completly 0'd out;

	this->hashTable[0].EPC = true;
	this->hashTable[0].LMR = true;
	this->hashTable[0].IPC = true;

	this->hashTable[1].RD = true;
	this->hashTable[1].LIR = true;
	this->hashTable[1].LMS = true;
	this->hashTable[1].LIO = true;

	// @Ghosh : nop

	this->hashTable[2].RMS = true;

	// @Ghosh : stop
	// @Ghosh : |->	Nothing to do!

	// @Ghosh : adi xx

	this->hashTable[3].EPC = true;
	this->hashTable[3].LMR = true;
	this->hashTable[3].IPC = true;

	this->hashTable[4].RD = true;
	this->hashTable[4].LOR = true;

	this->hashTable[5].EAR = true;
	this->hashTable[5].LAR = true;
	this->hashTable[5].SAF = 0x01; // ADD
	this->hashTable[5].RMS = true;

	// @Ghosh : sbi xx

	this->hashTable[6].EPC = true;
	this->hashTable[6].LMR = true;
	this->hashTable[6].IPC = true;

	this->hashTable[7].RD = true;
	this->hashTable[7].LOR = true;

	this->hashTable[8].EAR = true;
	this->hashTable[8].LAR = true;
	this->hashTable[8].SAF = 0x02; // SUB
	this->hashTable[8].RMS = true;

	// @Ghosh : xri xx

	this->hashTable[9].EPC = true;
	this->hashTable[9].LMR = true;
	this->hashTable[9].IPC = true;

	this->hashTable[10].RD = true;
	this->hashTable[10].LOR = true;

	this->hashTable[11].EAR = true;
	this->hashTable[11].LAR = true;
	this->hashTable[11].SAF = 0x03; // XOR
	this->hashTable[11].RMS = true;

	// @Ghosh : ani xx

	this->hashTable[12].EPC = true;
	this->hashTable[12].LMR = true;
	this->hashTable[12].IPC = true;

	this->hashTable[13].RD = true;
	this->hashTable[13].LOR = true;

	this->hashTable[14].EAR = true;
	this->hashTable[14].LAR = true;
	this->hashTable[14].SAF = 0x04; // AND
	this->hashTable[14].RMS = true;

	// @Ghosh : ori xx

	this->hashTable[15].EPC = true;
	this->hashTable[15].LMR = true;
	this->hashTable[15].IPC = true;

	this->hashTable[16].RD = true;
	this->hashTable[16].LOR = true;

	this->hashTable[17].EAR = true;
	this->hashTable[17].LAR = true;
	this->hashTable[17].SAF = 0x05; // OR
	this->hashTable[17].RMS = true;

	// @Ghosh : cmi xx

	this->hashTable[18].EPC = true;
	this->hashTable[18].LMR = true;
	this->hashTable[18].IPC = true;

	this->hashTable[19].RD = true;
	this->hashTable[19].LOR = true;

	this->hashTable[20].EAR = true;
	this->hashTable[20].SAF = 0x06; // CMP === SUB
	this->hashTable[20].RMS = true;

	// @Ghosh : ret <fl>

	this->hashTable[21].EFL = true;
	this->hashTable[21].RMS = true;

	this->hashTable[22].ESP = true;
	this->hashTable[22].LMR = true;
	this->hashTable[22].ISP = true;

	this->hashTable[23].RD = true;
	this->hashTable[23].LPC = true;
	this->hashTable[23].RMS = true;

	// @Ghosh : add <r>

	this->hashTable[24].ERG = true;
	this->hashTable[24].LOR = true;

	this->hashTable[25].EAR = true;
	this->hashTable[25].LAR = true;
	this->hashTable[25].SAF = 0x01; // ADD
	this->hashTable[25].RMS = true;

	// @Ghosh : sub <r>

	this->hashTable[26].ERG = true;
	this->hashTable[26].LOR = true;

	this->hashTable[27].EAR = true;
	this->hashTable[27].LAR = true;
	this->hashTable[27].SAF = 0x02; // SUB
	this->hashTable[27].RMS = true;

	// @Ghosh : xor <r>

	this->hashTable[28].ERG = true;
	this->hashTable[28].LOR = true;

	this->hashTable[29].EAR = true;
	this->hashTable[29].LAR = true;
	this->hashTable[29].SAF = 0x03; // XOR
	this->hashTable[29].RMS = true;

	// @Ghosh : and <r>

	this->hashTable[30].ERG = true;
	this->hashTable[30].LOR = true;

	this->hashTable[31].EAR = true;
	this->hashTable[31].LAR = true;
	this->hashTable[31].SAF = 0x04; // AND
	this->hashTable[31].RMS = true;

	// @Ghosh : or <r>

	this->hashTable[32].ERG = true;
	this->hashTable[32].LOR = true;

	this->hashTable[33].EAR = true;
	this->hashTable[33].LAR = true;
	this->hashTable[33].SAF = 0x05; // OR
	this->hashTable[33].RMS = true;

	// @Ghosh : cmp <r>

	this->hashTable[34].ERG = true;
	this->hashTable[34].LOR = true;

	this->hashTable[35].EAR = true;
	this->hashTable[35].LAR = true;
	this->hashTable[35].SAF = 0x06; // CMP
	this->hashTable[35].RMS = true;

	// @Ghosh : movs <r>

	this->hashTable[36].ERG = true;
	this->hashTable[36].LAR = true;
	this->hashTable[36].SAF = 0x0F; //PASSO
	this->hashTable[36].RMS = true;

	// @Ghosh : movd <r>

	this->hashTable[37].EAR = true;
	this->hashTable[37].LRG = true;
	this->hashTable[37].RMS = true;

	// @Ghosh : movi <r> xx

	this->hashTable[38].EPC = true;
	this->hashTable[38].LMR = true;
	this->hashTable[38].IPC = true;

	this->hashTable[39].RD  = true;
	this->hashTable[39].LRG = true;
	this->hashTable[39].RMS = true;

	// @Ghosh : stor <r>

	this->hashTable[40].EAR = true;
	this->hashTable[40].LMR = true;

	this->hashTable[41].ERG = true;
	this->hashTable[41].WR  = true;
	this->hashTable[41].RMS = true;

	// @Ghosh : load <r>

	this->hashTable[42].EAR = true;
	this->hashTable[42].LMR = true;

	this->hashTable[43].RD  = true;
	this->hashTable[43].LRG = true;
	this->hashTable[43].RMS = true;

	// @Ghosh : push <r>

	this->hashTable[44].DSP = true;

	this->hashTable[45].ESP = true;
	this->hashTable[45].LMR = true;

	this->hashTable[46].ERG = true;
	this->hashTable[46].WR  = true;
	this->hashTable[46].RMS = true;

	// @Ghosh : pop <r>

	this->hashTable[47].ESP = true;
	this->hashTable[47].LMR = true;
	this->hashTable[47].ISP = true;

	this->hashTable[48].RD  = true;
	this->hashTable[48].LRG = true;
	this->hashTable[48].RMS = true;

	// @Ghosh : jumpd <fl> xx

	this->hashTable[49].EPC = true;
	this->hashTable[49].LMR = true;
	this->hashTable[49].IPC = true;
	this->hashTable[49].EFL = true;
	this->hashTable[49].RMS = true;

	this->hashTable[50].RD  = true;
	this->hashTable[50].LPC = true;
	this->hashTable[50].RMS = true;

	// @Ghosh : jmpr <fl>

	this->hashTable[51].EFL = true;
	this->hashTable[51].RMS = true;

	this->hashTable[52].EAR = true;
	this->hashTable[52].LPC = true;
	this->hashTable[52].RMS = true;

	// @Ghosh : cd <fl> xx

	this->hashTable[53].EPC = true;
	this->hashTable[53].LMR = true;
	this->hashTable[53].IPC = true;
	this->hashTable[53].EFL = true;
	this->hashTable[53].RMS = true;

	this->hashTable[54].RD  = true;
	this->hashTable[54].LOR = true;
	this->hashTable[54].DSP = true;

	this->hashTable[55].ESP = true;
	this->hashTable[55].LMR = true;

	this->hashTable[56].EPC = true;
	this->hashTable[56].WR  = true;

	this->hashTable[57].EOR = true;
	this->hashTable[57].LPC = true;
	this->hashTable[57].RMS = true;

	// @Ghosh : cr <fl>

	this->hashTable[58].EFL = true;
	this->hashTable[58].RMS = true;

	this->hashTable[59].DSP = true;

	this->hashTable[60].ESP = true;
	this->hashTable[60].LMR = true;

	this->hashTable[61].EPC = true;
	this->hashTable[61].WR  = true;

	this->hashTable[62].EAR = true;
	this->hashTable[62].LPC = true;
	this->hashTable[62].RMS = true;
}

ROM::~ROM () {
	this->hashTable.clear();
}

void ROM::setMicroinstruction () {
	microinstruction->setContent(this->hashTable[ microprogramSequencer->getContent() ]);
}

ROM::ROM (std::string path) {

}

ROM::ROM (std::fstream infile) {

}

ROM::ROM (std::ifstream infile) {

}

#endif
