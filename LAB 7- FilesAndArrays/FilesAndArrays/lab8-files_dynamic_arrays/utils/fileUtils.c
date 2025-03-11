#include "../utils/fileUtils.h"

#include <lab7.h>

//Defined MAX constant
const int MAXIMUM = 100;

/*
 * Quick & Dirty File Read
 */
void readFileName(char * fn)
{
	printf("Please enter the name of the input file: ");
	scanf("%s", fn);
}


/*
 * This is supposed to read the file name and determine if its valid
 * Could've done recursion but kept having logic malfunctions with premature error msgs
 * Uses 3 methods to check filename to make sure it won't break
 * Re-Write Count: 5
 */

FILE * openInputFile(char * fn)
{
	//IF FIRST ATTEMPT IS VALID:
	//__________________________


	//Set FileName and TempPath
	FILE * fin = NULL;
	char tempPath[MAXIMUM];

	// Try with "../" prefix first
	snprintf(tempPath, MAXIMUM, "../%s", fn);
	fin = fopen(tempPath, "r");

	// If that worked, update fn and return
	if (fin != NULL) {
		strcpy(fn, tempPath);
		return fin;
	}

	//SECOND ATTEMPT USING FALLBACK:
	//______________________________

	fin = fopen(fn, "r");

	// If that worked, return
	if (fin != NULL) {
		return fin;
	}


	//LAST ATTEMPT METHOD TO READ THE FILENAME:
	//________________________________________

	// If you get here, you messed up...
	// Loop until we get a valid file
	while (fin == NULL) {

		//Error and Try Again Prompting
		printf("File not found\n");
		readFileName(fn);

		// Try same loop
		snprintf(tempPath, MAXIMUM, "../%s", fn);
		fin = fopen(tempPath, "r");

		// If that worked, update fn and break
		if (fin != NULL) {
			strcpy(fn, tempPath);
			break;
		}

		// Try just the filename
		fin = fopen(fn, "r");

		// If that worked, break
		if (fin != NULL) {
			break;
		}
	}

	return fin;
}


//Strip Data Function
void strip(char * array)
{
	int len = strlen(array);
	
	int x = 0;
	
	while(x < len)
	{
		if(array[x] == '\r')
			array[x] = '\0';
			
		else if(array[x] == '\n')
			array[x] = '\0';
			
		x++;
	}// end while

}// end strip