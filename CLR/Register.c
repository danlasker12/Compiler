#include "Register.h"  

/*
KEY_VALUE opcodesValues[MAX_OPCODES] = {
	{ "rmov", 0 },
	{ "radd", 1 },
	{ "rsub", 2 },
	{ "rprintD", 3 },
	{ "rprintX", 4 },
	{ "rprintS", 5 },
	{ "rxor", 6 },
	{ "rcmp", 7 },
	{ "imov", 100 },
	{ "iadd", 101 },
	{ "isub", 102 },
	{ "ixor", 103 },
	{ "icmp", 104 },
	{ "jmp", 200 },
	{ "je", 201 },
	{ "jg", 202 },
	{ "jl", 203 },
	{ 0,0 }
};
*/

/*
KEY_VALUE registersValues[MAX_REGISTERS] = {
	{ "r0" , 0 },
	{ "r1" , 1 },
	{ "r2" , 2 },
	{ "r3" , 3 },
	{ "r4" , 4 },
	{ "r5" , 5 },
	{ "r6" , 6 },
	{ "r7" , 7 },
	{ "r8" , 8 },
	{ "r9" , 9 },
	{ "r$" , 10 },// Result of CMP - 1: <, 2: = ,3: >
	{ "ri" , 11 },//Register that contains address
	{ 0,0 }
};
*/

//Initialize registers
KEY_VALUE_INT registers[MAX_REGISTERS] = {
	{ 0 , ILLEGAL_NUM },
	{ 1 , ILLEGAL_NUM },
	{ 2 , ILLEGAL_NUM },
	{ 3 , ILLEGAL_NUM },
	{ 4 , ILLEGAL_NUM },
	{ 5 , ILLEGAL_NUM },
	{ 6 , ILLEGAL_NUM },
	{ 7 , ILLEGAL_NUM },
	{ 8 , ILLEGAL_NUM },
	{ 9 , ILLEGAL_NUM },
	{ 10 , ILLEGAL_NUM },
	{ 11 , 0}, 
	{ 0,0 }
};

int setRegisterValue(int reg, int newValue) {
	int i;
	for (i = 0; i < MAX_REGISTERS; i++) {
		if (reg == registers[i].key) {
			registers[i].value = newValue;
			return 1;
		}
	}
	return 0;
}

int getRegisterValue(int reg) {
	int i;
	for (i = 0; i < MAX_REGISTERS; i++) {
		if (reg == registers[i].key) {
			return registers[i].value;
		}
	}
	return ILLEGAL_NUM;
}