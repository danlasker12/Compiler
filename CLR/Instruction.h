#pragma once 
#pragma comment(lib, "Ws2_32.lib")
#include "Utils.h"
#include "FileManagement.h"
#include <Winsock2.h>

union BODY {
	struct R {
		unsigned reg1 : 4;
		unsigned reg2 : 16;
	};
	struct I {
		unsigned reg : 4;
		int num : 16;
	};
	struct J {
		int addr : 20;
	};
};

typedef struct _INSTRUCTION {
	//__int32 instruction;
	unsigned int type : 4;
	unsigned int opcodeValue : 8;
	union BODY body;
}INSTRUCTION,*PINSTRUCTION;

extern PINSTRUCTION instructions;
extern int instructionsSize;

int hexToInstructions(__int32* hexValues,int sizeFile);
INSTRUCTION newInstruction(__int32 hexValue);
void printInstruction(INSTRUCTION inst);