#include "Instructions.h"

INSTRUCTION instructions[MAX_INSTRUCTIONS] = { 0 };
int indexInstructions = 0;

INSTRUCTION makeInstruction(int type, int opcode, int first,int second) {
	INSTRUCTION inst;

	inst.type = type;
	inst.opcode = opcode;

	if (second == ILLEGAL_NUM) {
		inst.exec = first;
	}
	else {
		inst.exec = first;
		inst.exec = inst.exec << 16;
		inst.exec = inst.exec | second;
	}
	return inst;
}

void toStringInstruction(INSTRUCTION inst) {
	printf("%.8x\n",inst);
}

int dumpInstructionData(INSTRUCTION inst,char buffer[]) {
	//snprintf(buffer, "%X", &inst,4);
	memcpy(buffer, &inst, 4);
	return 1;
}

void logInst(INSTRUCTION inst) {
	int reg1, reg2, value,mask;
	if (inst.type == 1) {
		mask = 0xF0000;
		reg1 = mask & inst.exec;
		reg1 = reg1 >> 16;
		mask = 0x0FFFF;
		value = mask & inst.exec;
		printf("I \t OPCODE %s \t REGISTER %s \t VALUE %d\n",getOpcodeName(inst.opcode),getRegisterName(reg1),value);
	}
	else if (inst.type == 2) {
		mask = 0xF0000;
		reg1 = mask & inst.exec;
		reg1 = reg1 >> 16;
		mask = 0x0FFFF;
		reg2 = mask & inst.exec;
		printf("R \t OPCODE %s \t REGISTER_1 %s \t REGISTER_2 %s\n", getOpcodeName(inst.opcode), getRegisterName(reg1), getRegisterName(reg2));
	}
	else if (inst.type == 3) {
		printf("J \t OPCODE %s \t ADDRESS %d\n", getOpcodeName(inst.opcode), inst.exec);
	}
}
