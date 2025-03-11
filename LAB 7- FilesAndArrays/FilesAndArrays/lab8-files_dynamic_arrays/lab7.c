#include "lab7.h"

extern const int MAX;

int menu()
{
	int choice;
	do
	{
		printf("\n"); //Make it easier to read
		printf("Please enter a menu choice \n");
		printf("_____________________________\n");
		printf("1) Display Max Temp\n");
		printf("2) Display Min Temp\n");
		printf("3) Display Average Temp\n");
		printf("4) Display Median Temp\n");
		printf("5) Fill an array by reading from a new file\n");
		printf("6) Quit\n");
		printf("Choice --> ");
		scanf("%d", &choice);
	}	while(choice < 1 || choice > 6);

	return choice;
}

int readDays(FILE * fin)
{
	//Define days
	int days;

	//Count number of and record
	fscanf(fin, "%d", &days);

	//Return days
	return days;
}


int * fillArray(int total, FILE * fin)
{
	//Memory Allocate temp and scan the file
	int * temp = (int *)malloc(sizeof(int) * total);

	//Error Condition
	if (temp == NULL) {
		printf("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	//Default Logic Populates
	for(int i = 0; i < total; i++) {
		fscanf(fin, "%d", &temp[i]);
	}

	//Return temp
	return temp;

}

void displayMaxTemp(int * array, int total) {

	//Should already be sorted
	printf("\n");
	printf("Max Temp is : %d\n", array[total - 1]);
	printf("");
}


void displayMinTemp(int * array, int total) {

	//Should be min index already
	printf("\n");
	printf("Min Temp is: %d\n", array[0]);
	printf("");
}


void displayAvgTemp(int * array, int total) {

	//Init Sum Var
	int sum = 0;

	//Tally Sum
	for(int i = 0; i < total; i++) {
		sum += array[i];
	}

	//Assign var Avg & Calculate
	int avg = sum / total;

	printf("\n");
	printf("Average Temp is : %d\n", avg);
	printf("");
}


void displayMedianTemp(int * array, int total) {

	//Determine odd or even
	//Find Middle 2 if even
	//Find Middle if odd

	//Median Variables
	int median;

	//Used For Even Number of Elements
	int median1;
	int median2;

	//Even Number of Elements
	if (total % 2 == 0) {

		//Find two mids
		median1 = array[total/2 - 1];
		median2 = array[total/2];

		//Output
		printf("\n");
		printf("Median Temp is : %d & %d\n", median1,median2);
		printf("");

	}

	//Odd Number of Elements
	//Fallback Condition If Even Isn't Met
	else {

		//Calc Odd Median
		median = array[total/2];

		//Output
		printf("\n");
		printf("Median is : %d\n", median);
		printf("");

	}

}


void cleanUp(int * array) {

	//Clear the Array
	free(array);
}

//Don't Touch! Already Functional
void printArray(int * array, int total)
{
	int x;

	printf("\n");
	printf("[");
	for(x = 0; x < total - 1; x++)
		printf("%d, ", array[x]);

	//Array Output
	printf("%d]\n", array[total - 1]);
	printf("");
}

