#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lab5.h"

const int MAX = 25;

int main(int argc, char ** argv)
{
    int total, array[MAX], value;
    double mean, median;

    total = readTotal(); // must ensure total is > 0 and <= to MAX or 999 to quit

    while(total != 999)
    {
        fillArray(total, array);  //fills the array with numbers up to total
        selectionSort(array, total); // sorts the array
        mean = calcMean(total, array);
        median = calcMedian(array, total);
        displayResults(mean, median); // prints to the screen the mean of the array is [man value] and the median is [median value] \n

        total = readTotal();

    }// end while

    return 0;

}// end main