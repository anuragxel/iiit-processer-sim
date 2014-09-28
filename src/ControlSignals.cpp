#ifndef _CONTROL_SIGNALS_CPP
#define _CONTROL_SIGNALS_CPP

#include "ControlSignals.h"

void EAR ()
{
	databus->setContent(accumulator->getContent());
}

void RAR ()
{
	accumulator->setContent( 0 );
}

void LAR ()
{
	accumulator->setContent(alu->getContent());
}

#endif
