/*
    Anthony Mendez
    06/15/22

    This program demonstrates shellSort on a random array
    by printing the progress of swaps
*/
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

// Function prototypes
int getRand();
void fillArray(int *array, int size);
void printArray(int *array, int size);
void shellSort(int *array, int size, int *gapArray, int gapSize);
void insertionSortInterleaved(int *array, int size, int start, int gap);

// Global Constants
const int HIGH = 99;
const int LOW = 10;

int main()
{
    // Set the random number seed
    srand(static_cast<int>(time(0)));

    // Define variables
    const int SIZE = 20;
    const int GAPSIZE = 3;
    int array[SIZE];
    int gapArray[GAPSIZE] = {5, 3, 1};

    // Fill array with random numbers and print initial conents
    fillArray(array, SIZE);
    cout << "The unsorted array is: " << endl;
    printArray(array, SIZE);

    // Sort the array and print its progress
    cout << "Performing shellSort: " << endl;
    shellSort(array, SIZE, gapArray, GAPSIZE);

    // Display the final sorted array
    cout << "The sorted array is: " << endl;
    printArray(array, SIZE);

    return 0;
}

// Function to get a random digit
int getRand()
{
    return rand() % (HIGH - LOW + 1) + LOW;
}

// Function to fill array with random digits
void fillArray(int *array, int size)
{
    for (int index = 0; index < size; index++)
    {
        array[index] = getRand();
    }
}

// Function to print the contents of an array
void printArray(int *array, int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << array[index] << " ";
    }
    cout << endl << endl;
}

// Function to sort array
void shellSort(int *array, int size, int *gapArray, int gapSize)
{
    printArray(array, size);
    for (int gapIndex = 0; gapIndex < gapSize; gapIndex++)
    {
        for (int index = 0; index < gapArray[gapIndex]; index++)
        {
            insertionSortInterleaved(array, size, index, gapArray[gapIndex]);
        }
    }
}

// Helper function for insertionSort
void insertionSortInterleaved(int *array, int size, int start, int gap)
{
    int hold;
    int temp;

    for (int index = start + gap; index < size; index += gap)
    {
        hold = index;
        while (hold - gap >= start && array[hold] < array[hold - gap])
        {
            temp = array[hold];
            array[hold] = array[hold - gap];
            array[hold - gap] = temp;
            hold -= gap;
            printArray(array, size);
        }
    }
}
