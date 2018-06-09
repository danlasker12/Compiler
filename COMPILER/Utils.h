#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LEN_NAME 16

typedef struct _KEY_VALUE {
	char name[MAX_LEN_NAME];
	int value;
} KEY_VALUE, *PKEY_VALUE;

unsigned int len(int num);
void swapToLittleEndian(char* instructionStr);
int myatoi(char* str,int* newInt);