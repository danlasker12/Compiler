#pragma comment(lib, "Ws2_32.lib")
#include "Utils.h"
#include "FileManagement.h"
#include "Instruction.h"
#include "Assembler.h"
#include "Register.h"

unsigned int sizeFile;
__int32* hexValues;

int main(int argc, char* argv[]) {

	if (argc < 2) {
		printf("No Arguments\n");
		system("PAUSE");
		return -1;
	}

	if (!(hexValues = loadFile("test.dobj", &sizeFile))) {
		system("PAUSE");
		return -1;
	}

	if (!hexToInstructions(hexValues, sizeFile)) {
		system("PAUSE");
		return -1;
	}

	for (int i = 0; i < instructionsSize; i++) {
		printInstruction(instructions[i]);
	}
	while (getRegisterValue(11) < instructionsSize) {

		if (!executeInstruction(instructions[getRegisterValue(11)])) {
			break;
		}
	}

	system("PAUSE");
	return 0;
}
