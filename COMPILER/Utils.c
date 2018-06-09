#include "Utils.h"

unsigned int len(int num) {
	if (num < 10) {
		return 1;
	}
	return len(num / 10) + 1;
}

void swapToLittleEndian(char* instructionStr) {
	char temp[2];
	int i,j;
	for (i = 0,j = strlen(instructionStr)-2; i<j; i += 2,j -= 2) {
		strncpy(temp, instructionStr + i, 2);
		instructionStr[i] = instructionStr[j]; instructionStr[i+1] = instructionStr[j+1];
		instructionStr[j] = temp[0]; instructionStr[j+1] = temp[1];
	}
}

int myatoi(char* input, int* newInt) {
	int i = 0;
	if (!input) {
		return 0;
	}
	if (input[0] == '-') {
		i = 1;
	}
	for (; i < strlen(input); i++) {
		if (input[i] < '0' || input[i] > '9') {
			return 0;
		}
	}
	*newInt = atoi(input);
	return 1;
}
