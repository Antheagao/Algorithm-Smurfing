/*
    Anthony Mendez
    06/16/22

    This program demonstrates quickSort on a random array
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
void quickSort(int *array, int start, int end);
int partition(int *array, int start, int end);

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
    cout << "Performing quickSort: " << endl;
    quickSort(array, 0, SIZE - 1);

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
void quickSort(int *array, int start, int end)
{
    int high;

    if (end <= start)
    {
        return;
    }

    high = partition(array, start, end);
    quickSort(array, start, high);
    quickSort(array, high + 1, end);
}

// Function to partition for quickSort
int partition(int *array, int start, int end)
{
    int mid;
    int pivot;
    int high;
    int low;
    int temp;
    bool done;

    mid = start + (end - start) / 2;
    pivot = array[mid];

    low = start;
    high = end;

    done = false;
    while (!done)
    {
        while (array[low] < pivot)
        {
            low = low + 1;
        }
        while (pivot < array[high])
        {
            high = high - 1;
        }
        if (low >= high)
        {
            done = true;
        }
        else
        {
            temp = array[low];
            array[low] = array[high];
            array[high] = temp;

            low = low + 1;
            high = high - 1;
            printArray(array, end + 1);
        }
    }
    return high;
}
