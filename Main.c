#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Utils.h"
#include "Instructions.h"
#include "Parser.h"
#include "FileManagement.h"

char* str;
unsigned int size;

int main(int argc,char* argv[]) {

	if (argc < 2) {
		printf("No arguments\n - USAGE: <FILE.dan> <OUTPUT_NAME>");
		system("PAUSE");
		return -1;
	}

	str = fileToStr(argv[1],&size);

	if (!parseFile(str, size)) {
		system("PAUSE");
		return -1;
	}

	if (!instructionsToFile(argv[2])) {
		system("PAUSE");
		return -1;
	}

	/*if (!strncmp(argv[3], "-v", 2)) {
	
	}*/

	system("PAUSE");
	return 0;
}