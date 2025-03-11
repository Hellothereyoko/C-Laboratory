//
// Created by Yoko Parks on 2/10/25.
//


#include <stdlib.h>
#include <stdbool.h>
#include "lab5.h"

//Pass constant
extern const int MAX;


/* DEBUG FUNCTION PRINTING ARRAY

void printArray(int array[], int total) {
    printf("Array elements: ");
    for (int i = 0; i < total; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
*/

int readTotal() {
    //Summon total
    int total;
    bool continueFlag = false;

    //Loop for collecting info from user
    while (continueFlag == false) {
        printf("Enter the number of elements (1-%d, or 999 to quit): ", MAX);

        // Check if input is a valid integer
        if (scanf("%d", &total) == 1) {
            // Exit Condition
            if (total == 999) {
                printf("Bye-Bye!\n");
                exit(0);
            }
            // Valid Condition
            if (total > 0 && total <= MAX) {
                continueFlag = true;
            }

            else {
                // Invalid Condition
                printf("Invalid input. Please enter a number between 1 and %d.\n", MAX);
            }
        }

            else {
            // Clear the input buffer if scanf fails
            while (getchar() != '\n'); // Clear the buffer
            printf("Invalid input. Please enter a valid number.\n");
        }
    }

    return total;
}


void fillArray(int total, int array[]) {
    //Summon Value
    int value;

    //Enter elements in loop
    for (int i = 0; i < total; i++) {
        printf("Please Enter Element %d: ", i);

        //Collect info & assign to array
        scanf("%d", &value);
        array[i] = value;
    }
}



void selectionSort(int array[], int total) {

    //Loop to increment i
    for (int i = 0; i < total - 1; i++) {

        //Define min IDX to i
        int minIndex = i;

        //For every i compare current val (j) to minIDX
        for (int j = i + 1; j < total; j++) {

            //If j < minIndex shift left
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        //Assign temp var to minIDX
        int temp = array[minIndex];

        //i gets to minIDX
        array[minIndex] = array[i];

        //Reiterate until exhaustion
        array[i] = temp;
    }
}



double calcMean(int total, int array[]) {

    //Define sum as a var and track
    int sum = 0;

    //Loop to add val of i to sum
    for (int i = 0; i < total; i++) {
        sum += array[i];
    }

    //Calculate mean and return as a double
    return(double) sum / total;
}


double calcMedian(int array[], int total) {

    //Odd Length Operation
    if (total % 2 == 1) {

        //Return Median
        return array[total / 2];
    }

    //Even Length Operation
    if (total % 2 == 0){

        //Return Median
        return (array[total / 2 - 1] + array[total / 2]) / 2.0;
    }
}

void displayResults(double mean , double median) {

   //Print Mean
    printf("The mean is: %.2f \n", mean);

   //Print Median
    printf("The median is: %.2f \n", median);


   //DEBUG PRINT ARRAY
    //printArray(array, total);
    //add int array[] & int total to displayResults in order to make this work
    //Do it in both lab5.h and lab5.c
}
