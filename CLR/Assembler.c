#include "Assembler.h"

int executeInstruction(INSTRUCTION inst) {
	int execution;
	if (inst.type == 1) {
		execution = executeI(inst);
	}else if (inst.type == 2) {
		execution = executeR(inst);
	}
	else if (inst.type == 3) {
		execution = executeJ(inst);
	}

	if (!execution) {
		return 0;
	}
	else {
		return 1;
	}
}


int executeI(INSTRUCTION inst) { 
	
	int opcode = inst.opcodeValue;
	int reg1 = inst.body.reg1;
	int regValue1 = getRegisterValue(reg1);
	int num = inst.body.num;

	if (opcode == 100) {
		setRegisterValue(reg1, num);
	}
	else if (opcode == 101) {
		if (regValue1 == ILLEGAL_NUM) {
			printf("Instruction - iadd: register 1 is unitialized - r%d \n", reg1);
			return 0;
		}
		setRegisterValue(reg1,regValue1 + num);
	}
	else if (opcode == 102) {
		if (regValue1 == ILLEGAL_NUM) {
			printf("Instruction - isub: register 1 is unitialized - r%d \n", reg1);
			return 0;
		}
		setRegisterValue(reg1, regValue1 - num);
	}
	else if (opcode == 103) {
		if (regValue1 == ILLEGAL_NUM) {
			printf("Instruction - ixor: register 1 is unitialized - r%d \n", reg1);
			return 0;
		}
		setRegisterValue(reg1, regValue1 ^ num);
	}
	else if (opcode == 104) {
		if (regValue1 == ILLEGAL_NUM) {
			printf("Instruction - icmp: register 1 is unitialized - r%d \n", reg1);
			return 0;
		}
		if (num > regValue1) {
			setRegisterValue(10, 3);
		}
		else if (num < regValue1) {
			setRegisterValue(10, 1);
		}
		else {
			setRegisterValue(10, 2);
		}
	}
	setRegisterValue(11, getRegisterValue(11) + 1);//Incr ri (address)
	return 1;
}

int executeJ(INSTRUCTION inst) { 
	int opcode = inst.opcodeValue;
	int address = inst.body.addr;
	int finalAddress = getRegisterValue(11) + address;
	int rCmp = getRegisterValue(10);

	if (finalAddress < 0 || finalAddress >= instructionsSize) {
		printf("Error Incorrect address - jmp\je\jg\jl, OPCODE VALUE: %d\n",opcode);
		return 0;
	}
	if (opcode == 200) {
		setRegisterValue(11,finalAddress);
	}
	else if (opcode == 201) {
		if (rCmp == 2) {
			setRegisterValue(11, finalAddress);
		}
		else {
			setRegisterValue(11, getRegisterValue(11) + 1);
		}
	}
	else if (opcode == 202) {
		if (rCmp == 3) {
			setRegisterValue(11, finalAddress);
		}
		else {
			setRegisterValue(11, getRegisterValue(11) + 1);
		}
	}
	else if (opcode == 203) {
		if (rCmp == 1) {
			setRegisterValue(11, finalAddress);
		}
		else {
			setRegisterValue(11, getRegisterValue(11) + 1);
		}
	}

	return 1;
}

int executeR(INSTRUCTION inst) {
	
	int opcode = inst.opcodeValue;
	int reg1 = inst.body.reg1;
	int regValue1 = getRegisterValue(reg1);
	int reg2 = inst.body.reg2;
	int regValue2 = getRegisterValue(reg2);

	if (opcode == 0 ) {
		if (regValue2 == ILLEGAL_NUM) {
			printf("Instruction - rmov: register 2 is unitialized - r%d\n",reg2);
			return 0;
		}
		setRegisterValue(reg1, regValue2);
	}
	else if (opcode == 1) {
		if (regValue1 == ILLEGAL_NUM || regValue2 == ILLEGAL_NUM) {
			printf("Instruction - radd: register 1 and register 2 are unitialized - r%d - r%d\n", reg1,reg2);
			return 0;
		}
		setRegisterValue(reg1, regValue1 + regValue2);
	}
	else if (opcode == 2) {
		if (regValue1 == ILLEGAL_NUM || regValue2 == ILLEGAL_NUM) {
			printf("Instruction - rsub: register 1 and register 2 are unitialized - r%d - r%d\n", reg1, reg2);
			return 0;
		}
		setRegisterValue(reg1, regValue2 - regValue1);
	}
	else if (opcode == 3) {
		printf(">>> %d\n", regValue2);
	}
	else if (opcode == 4) {
		printf(">>> %x\n", regValue2);
	}
	else if (opcode == 5) {
		printf(">>> %s\n", regValue2);
	}
	else if (opcode == 6) {
		if (regValue1 == ILLEGAL_NUM || regValue2 == ILLEGAL_NUM) {
			printf("Instruction - rxor: register 1 and register 2 are unitialized - r%d - r%d\n", reg1, reg2);
			return 0;
		}
		setRegisterValue(reg1, regValue1 ^ regValue2);
	}
	else if (opcode == 7) {
		if (regValue1 == ILLEGAL_NUM && regValue2 == ILLEGAL_NUM) {
			printf("Instruction - rcmp: register 1 and register 2 are unitialized - r%d - r%d\n", reg1, reg2);
			return 0;
		}
		if (regValue2 > regValue1) {
			setRegisterValue(10, 3);
		}
		else if (regValue2 < regValue1) {
			setRegisterValue(10, 1);
		}
		else {
			setRegisterValue(10, 2);
		}
	}
	setRegisterValue(11, getRegisterValue(11) + 1);//Incr ri (address)
	return 1;
}