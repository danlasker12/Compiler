#include "FileManagement.h"

unsigned int getSizeFile(FILE* file) {
	unsigned int size;
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);
	return size;
}

char* fileToStr(char* nameFile,unsigned int* size) {
	char* str;
	FILE* file;

	file = fopen(nameFile, "r");
	if (!file) {
		printf("INCORECT FILE - Can't open file\n");
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

__int32* loadFile(char* name,unsigned int* size) {
	FILE* file;
	file = fopen(name, "r");
	if (!file) {
		printf("Error opening File\n");
		return 0;
	}
	*size = getSizeFile(file);
	__int32* hexValues;
	hexValues = (__int32*)malloc((*size)); 
	memset(hexValues, 0, *size);
	fread(hexValues, 1, *size, file);
	//for (int i = 0; i < *size/4; i++) { printf("%x\n",hexValues[i]); }
	fclose(file);
	return hexValues;
}