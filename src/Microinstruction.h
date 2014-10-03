#ifndef _MICROINSTRUCTION_H
#define _MICROINSTRUCTION_H

class Microinstruction {
	public:
		bool RD;
		bool WR;

		bool LMR;

		bool EPC;
		bool IPC;
		bool LPC;

		bool ESP;
		bool ISP;
		bool DSP;
		bool LSP;

		bool LIR;

		bool LMS;
		bool RMS;

		bool RFL;

		bool LIO;

		bool LRG;
		bool ERG;
		int SRG;

		bool LAR;
		bool RAR;
		bool EAR;

		int SAF;

		bool LOR;
		bool ROR;
		bool EOR;

		Microinstruction();
		~Microinstruction();
};

#endif
