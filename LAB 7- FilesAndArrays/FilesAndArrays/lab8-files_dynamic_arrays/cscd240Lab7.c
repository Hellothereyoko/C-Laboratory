#include "lab7.h"
#include "./utils/fileUtils.h"
#include "./utils/sortUtils.h"

const int MAX = 100;

int main()
{

	int total, choice;
	int * temps;
	FILE * fin = NULL;
	char fn[MAX];

	readFileName(fn);	
	fin = openInputFile(fn);

	total = readDays(fin);
	temps = fillArray(total, fin);
	selectionSort(temps, total);
	printArray(temps, total);

	do
	{
		choice = menu();

		if(choice == 1)
		{
			displayMaxTemp(temps, total);

		}// end choice == 1

		else if(choice == 2)
		{
			displayMinTemp(temps, total);
		}// end choice == 2

		else if(choice == 3)
		{
			displayAvgTemp(temps, total);
		}// end choice == 3

		else if(choice == 4)
		{
			displayMedianTemp(temps, total);

		}// end choice == 4

		else if(choice == 5)
		{
			fclose(fin);
			fin = NULL;
			cleanUp(temps);
			temps = NULL;
			
			readFileName(fn);
			fin = openInputFile(fn);
			
			total = readDays(fin);
			temps = fillArray(total, fin);
			selectionSort(temps, total);

			printArray(temps, total);
		}// end choice == 6

	}while(choice != 6);

	fclose(fin);
	fin = NULL;

	cleanUp(temps);
	temps = NULL;

}// end main

