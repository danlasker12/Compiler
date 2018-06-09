#include "Instruction.h"

PINSTRUCTION instructions;
int instructionsSize;


void printInstruction(INSTRUCTION inst) {
	printf("TYPE %d, OPCODE VALUE %d, ",inst.type,inst.opcodeValue);
	if (inst.type == 1) {
		printf("REG %d, NUM %d\n",inst.body.reg,inst.body.num);
	}
	else if (inst.type == 2) {
		printf("REG1 %d, REG2 %d\n", inst.body.reg1, inst.body.reg2);
	}
	else {
		printf("ADDRESS %d\n", inst.body.addr);
	}
}

int hexToInstructions(__int32* hexValues, int sizeFile) {
	int i;
	instructionsSize = (sizeFile - (4 * 2)) / 4; // 2 is number of signatures\header and 4 is size of each instruction
	instructions = (PINSTRUCTION)malloc(instructionsSize*sizeof(INSTRUCTION));
	for (i = 0; i < instructionsSize; i++) {
		instructions[i] = newInstruction(hexValues[i+1]);
	}
}

INSTRUCTION newInstruction(__int32 hexValue) {
	INSTRUCTION newInst;
	unsigned int mask;

	//hexValue = htonl(hexValue); Little Endian to Big Endian
	
	mask = 0xF0000000;
	newInst.type = (hexValue & mask) >> 28;

	mask = 0x0FF00000;
	newInst.opcodeValue = (hexValue & mask) >> 20;
	
	if (newInst.type == 1) {
		mask = 0x000F0000;
		newInst.body.reg = (mask & hexValue) >> 16;
		mask = 0x0000FFFF;
		newInst.body.num = mask & hexValue;
	}
	else if (newInst.type == 2) {
		mask = 0x000F0000;
		newInst.body.reg1 = (mask & hexValue) >> 16;
		mask = 0x0000FFFF;
		newInst.body.reg2 = mask & hexValue;
	}
	else {
		mask = 0x000FFFFF;
		newInst.body.addr = mask & hexValue;
	}

	return newInst;
}