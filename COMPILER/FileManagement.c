#include "FileManagement.h"

char* fileToStr(char* name, unsigned int* size) {
	char* str;
	FILE* file;

	file = fopen(name, "r");
	if (!file) {
		printf("INCORECT FILE\n");
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	*size = ftell(file);
	rewind(file);

	str = malloc(*size);
	memset(str, 0, *size);
	fread(str, sizeof(char), *size, file);
	fclose(file);
	return str;
}

int instructionsToFile(char* newFileName) {
	FILE* file;
	char bufferName[MAX_LEN_NAME_FILE],bufferInst[4];
	int dump,i,hexValue;

	strcpy(bufferName, newFileName);
	strcat(bufferName,".dobj"); //dobj = Dan Object File
	file = fopen(bufferName, "wb+");
	if (!file) {
		printf("Error opening file\n");
		return 0;
	}
	fwrite(HEADER_DAN_FILE,sizeof(char),sizeof(HEADER_DAN_FILE)-1,file);

	for (i = 0; i < indexInstructions; i++) {
		logInst(instructions[i]);
		dump = dumpInstructionData(instructions[i], bufferInst);
		fwrite(bufferInst,sizeof(char), sizeof(INSTRUCTION), file);
	}
	fwrite(SIGNATURE_DAN_FILE, sizeof(char), sizeof(SIGNATURE_DAN_FILE)-1, file);
	fclose(file);
	return 1;
}