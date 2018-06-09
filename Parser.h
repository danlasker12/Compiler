#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Instructions.h"
#include "Utils.h"

// Error codes
#define ERROR_INSTRUCTION_TYPE -4 

int parseFile(char* strFile,int sizeFile);
int parseInstructionJ(char* token, int* opcodeValue, int* first, int* second);
int parseInstructionR(char* token, int* opcodeValue, int* first, int* second);
int parseInstructionI(char* token, int* opcodeValue, int* first, int* second);
