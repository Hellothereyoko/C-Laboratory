#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFileName(char * fn);
FILE * openInputFile(char * fn);
void strip(char * array);

#endif