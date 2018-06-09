#include "Parser.h"

int parseFile(char* strFile,int sizeFile) {
	char* token,*buffer;
	int type,opcodeValue,first, second,tempLen;
	INSTRUCTION inst;

	buffer = (char*)malloc(sizeFile+1);
	strncpy(buffer, strFile, sizeFile);

	token = strtok(buffer, "\n");
	while (strcmp(token, ":)")) {
		tempLen = strlen(token) + 1;
		if (!token) {
			printf("ERROR - No signature ':)'\n");
			return 0;
		}
		else if (token[0] == 'i') {
			type = 1;
			if (!parseInstructionI(token, &opcodeValue, &first, &second)) {
				return 0;
			}
		}
		else if (token[0] == 'r') {
			type = 2;
			if (!parseInstructionR(token, &opcodeValue, &first, &second)) {
				return 0;
			}
		}
		else if (token[0] == 'j') {
			type = 3;
			if (!parseInstructionJ(token, &opcodeValue, &first, &second)) {
				return 0;
			}
		}
		else {
			printf("Syntax ERROR - Incorrect instruction type %s \n",token);
			return ERROR_INSTRUCTION_TYPE;
		}

		inst = makeInstruction(type, opcodeValue, first, second);
		instructions[indexInstructions++] = inst;
		buffer += tempLen;
		token = strtok(buffer, "\n");
	}

	return 1;
}

int parseInstructionJ(char* input, int* opcodeValue, int* first, int* second) {
	char* token;
	int temp;
	token = strtok(input, " ");

	if ((*opcodeValue = getOpcodeValue(token))<0) {
		printf("Syntax Error: JOpcode doesn't exist %s \n",token);
		return 0;
	}

	token = strtok(NULL, "\0");
	if (!token) {
		printf("Syntax Error: Address for jump\n");
		return 0;
	}
	if (myatoi(token, &temp) < 0) {
		printf("Syntax Error: Incorrect address %s\n",token);
		return 0;
	}
	*first = temp;
	*second = ILLEGAL_NUM;
	return 1;
}

int parseInstructionR(char* input, int* opcodeValue, int* first, int* second) {
	char* token,*ptr;
	int tempBool = 0;
	token = strtok(input, " ");
	if ((*opcodeValue = getOpcodeValue(token)) < 0) {
		printf("Syntax Error: ROpcode %s doesn't exist\n",token);
		return 0;
	}
	if (!strncmp(token, "rprint", 6)) {
		*second = ILLEGAL_NUM;
		tempBool = 1;
	}

	token = strtok(NULL, " ");
	if ((*first = getRegisterValue(token)) < 0) {
		printf("Syntax Error: Register %s doesn't exist\n",token);
		return 0;
	}
	if (tempBool) {
		return 1;
	}
	token = strtok(NULL, "\0");

	if ((*second = getRegisterValue(token)) < 0) {
		printf("Syntax Error: Register doesn't exist - %s\n",token);
		return 0;
	}
	return 1;

}
int parseInstructionI(char* input,int* opcodeValue, int* first, int* second) {
	char* token;
	int temp;
	token = strtok(input," ");
	if ((*opcodeValue = getOpcodeValue(token))<0) {
		printf("Syntax Error: IOpcode doesn't exist - %s\n",token);
		return 0;
	}
	token = strtok(NULL, " ");
	if ((*first = getRegisterValue(token))<0) {
		printf("Syntax Error: Register doesn't exist %s\n",token);
		return 0;
	}
	token = strtok(NULL, "\0");
	if (!myatoi(token,&temp)){
		printf("Syntax Error: Value for instructionI");
		return 0;
	}
	*second = temp;
	return 1;
}

