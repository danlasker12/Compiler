#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utils.h"

#define MAX_OPCODES 256 //2^8
#define MAX_REGISTERS 16 // 2^4
#define MAX_VAL 65536 //2^16

int getRegisterValue(char* registerName);
int getOpcodeValue(char* opcodeName);
char* getOpcodeName(int opcodeNum);
char* getRegisterName(int RegisterNum);