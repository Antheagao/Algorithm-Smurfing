/*
    Anthony Mendez
    06/17/22

    This program demonstrates mergeSort on a random array
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
void mergeSort(int *array, int start, int end);
void merge(int *array, int leftFirst, int leftLast, int rightLast);

// Global Constants
const int HIGH = 99;
const int LOW = 10;

int main()
{
    // Set the random number seed
    srand(static_cast<int>(time(0)));

    // Define variables
    const int SIZE = 20;
    int array[SIZE];

    // Fill array with random numbers and print initial conents
    fillArray(array, SIZE);
    cout << "The unsorted array is: " << endl;
    printArray(array, SIZE);

    // Sort the array and print its progress
    cout << "Performing mergeSort: " << endl;
    mergeSort(array, 0, SIZE - 1);

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
void mergeSort(int *array, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;

        mergeSort(array, start, mid);
        printArray(array, end + 1);
        mergeSort(array, mid + 1, end);
        printArray(array, end + 1);

        merge(array, start, mid, end);
        printArray(array, end + 1);
    }
}

// Helper function for merge sort
void merge(int *array, int leftFirst, int leftLast, int rightLast)
{
    int mergedSize = rightLast - leftFirst + 1;
    int *mergedNumbers = new int[mergedSize];

    int mergePos = 0;
    int leftPos = leftFirst;
    int rightPos = leftLast + 1;

    while (leftPos <= leftLast && rightPos <= rightLast)
    {
        if (array[leftPos] <= array[rightPos])
        {
            mergedNumbers[mergePos] = array[leftPos];
            leftPos++;
        }
        else
        {
            mergedNumbers[mergePos] = array[rightPos];
            rightPos++;
        }
        mergePos++;
    }
    while (leftPos <= leftLast)
    {
        mergedNumbers[mergePos] = array[leftPos];
        leftPos++;
        mergePos++;
    }
    while (rightPos <= rightLast)
    {
        mergedNumbers[mergePos] = array[rightPos];
        rightPos++;
        mergePos++;
    }
    for (mergePos = 0; mergePos < mergedSize; mergePos++)
    {
        array[leftFirst + mergePos] = mergedNumbers[mergePos];
    }

    delete[] mergedNumbers;
}
