#pragma once

#include "Instructions.h"
#include "Utils.h"

#define MAX_LEN_NAME_FILE 20
#define HEADER_DAN_FILE "!DAN"
#define SIGNATURE_DAN_FILE "DAN!"

char* fileToStr(char* name, unsigned int* size);
int instructionsToFile(char* newFileName);