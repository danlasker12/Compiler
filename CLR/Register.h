#pragma once
#include "Instruction.h"
#include "Utils.h"

#define MAX_OPCODES 256 //2^8
#define MAX_REGISTERS 16 // 2^4
#define MAX_VAL 65536 //2^16
#define ILLEGAL_NUM -999

extern KEY_VALUE_INT registers[];

int setRegisterValue(int reg,int newValue);
int getRegisterValue(int reg);