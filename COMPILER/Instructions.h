#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Opcode.h"

#define MAX_INSTRUCTIONS 100
#define ILLEGAL_NUM -999
#define INVALID_REGISTER -1
#define MAX_LEN_INSTRUCTION 30

/* INSTRUCTION form:
	SYNTAX type(I,R,J) - OpcodeValue(1-255) - exec(Adress,register,number)	
*/

typedef struct _INSTRUCTION {
	int exec : 20; //J->20,I->reg:4,num:16,R->reg1:4,reg2:16
//	union BODY b;
	unsigned int opcode : 8; // See Opcode.c
	unsigned int type : 4; // 1 = R, 2 = I, 3 = J
}INSTRUCTION;

extern INSTRUCTION instructions[MAX_INSTRUCTIONS];
extern int indexInstructions;

INSTRUCTION makeInstruction(int type,int opcode,int first,int second);
void toStringInstruction(INSTRUCTION inst);
int dumpInstructionData(INSTRUCTION inst,char buffer[]);
void logInst(INSTRUCTION inst);