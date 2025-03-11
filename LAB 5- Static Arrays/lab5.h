//
// Created by Yoko Parks on 2/10/25.
//

#ifndef LAB5_H
#define LAB5_H

#include <stdio.h>



//Read & Check total # of elements
int readTotal();

//Function for Array w/ Usr input
void fillArray(int total, int array[]);

//Function to sort array
void selectionSort(int array[], int total);

//Function to calc mean of array
double calcMean(int total, int array[]);

//Function to calc median of array
double calcMedian(int array[], int total);

//Function to display mean & median
void displayResults(double mean, double median);


#endif //LAB5_H
