#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN_NAME 16

typedef struct _KEY_VALUE {
	char name[MAX_LEN_NAME];
	int value;
} KEY_VALUE, *PKEY_VALUE;

typedef struct _KEY_VALUE_INT {
	int key;
	int value;
} KEY_VALUE_INT, *PKEY_VALUE_INT;