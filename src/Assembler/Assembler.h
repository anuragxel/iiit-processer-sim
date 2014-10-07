#ifndef _ASSEMBLER_H
#define _ASSEMBLER_H

#define MEMSIZE 256

#define IMMEINST 1
#define REGINST 2
#define JMPDINST 3
#define MOVIINST 4
#define CDINST 5

#include <iostream>
#include <string>
#include <map>
#include <fstream>

void initialize();
void assembleCode(std::string,std::string);

#endif