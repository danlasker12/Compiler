#include "Opcode.h"

KEY_VALUE opcodes[MAX_OPCODES] = {
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

KEY_VALUE registers[MAX_REGISTERS] = {
	{ "r0" , 0},
	{ "r1" , 1 },
	{ "r2" , 2 },
	{ "r3" , 3 },
	{ "r4" , 4 },
	{ "r5" , 5 },
	{ "r6" , 6 },
	{ "r7" , 7 },
	{ "r8" , 8 },
	{ "r9" , 9 },
	{ "r$" , 10},// Result of CMP - 1: <, 2: = ,3: >
	{0,0}
};

int getRegisterValue(char* registerName) {
	int i;
	for (i = 0; i < MAX_REGISTERS; i++) {
		if (!strcmp(registerName, registers[i].name)) {
			return registers[i].value;
		}
	}
	return -1;
}

int getOpcodeValue(char* opcodeName) {
	int i;
	for (i = 0; i < MAX_REGISTERS; i++) {
		if (!strcmp(opcodeName, opcodes[i].name)) {
			return opcodes[i].value;
		}
	}
	return -1;
}

char* getRegisterName(int registerNum) {
	int i;
	for (i = 0; i < MAX_REGISTERS; i++) {
		if (registerNum == registers[i].value) {
			return registers[i].name;
		}
	}
	return NULL;
}

char* getOpcodeName(int opcodeNum) {
	int i;
	for (i = 0; i < MAX_REGISTERS; i++) {
		if (opcodeNum == opcodes[i].value) {
			return opcodes[i].name;
		}
	}
	return NULL;
}