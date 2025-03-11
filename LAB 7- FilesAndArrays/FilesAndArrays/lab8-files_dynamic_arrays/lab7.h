#ifndef LAB7_H
#define LAB7_H

#include <stdio.h>
#include <stdlib.h>

int menu();

int readDays(FILE * fin);

void cleanUp(int * array);

int * fillArray(int total, FILE * fin);

void displayMaxTemp(int * array, int total);

void displayMinTemp(int * array, int total);

void displayAvgTemp(int * array, int total);

void displayMedianTemp(int * array, int total);

void printArray(int * array, int total);


#endif