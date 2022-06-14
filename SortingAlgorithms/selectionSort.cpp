/*
    Anthony Mendez
    06/14/22

    This program demonstrates selectionSort on a random array
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
void selectionSort(int *array, int size);

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
    cout << "Performing selectionSort: " << endl;
    selectionSort(array, SIZE);

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
void selectionSort(int *array, int size)
{
    int temp;
    int smallest;

    printArray(array, size);
    for (int hold = 0; hold < size - 1; hold++)
    {
        smallest = hold;
        for (int index = hold + 1; index < size; index++)
        {
            if (array[index] < array[smallest])
            {
                smallest = index;
            }
        }
        temp = array[hold];
        array[hold] = array[smallest];
        array[smallest] = temp;
        printArray(array, size);
    }
}
