/*
    Anthony Mendez
    06/13/22

    This program demonstrates binary search using an
    array with random values and a randomly key
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

// Function prototypes
int getRand();
void fillArray(int *array, int size);
void printArray(int *array, int size);
void selectionSort(int *array, int size);
int binarySearch(int *array, int size, int key);
void displayCursor(int index);

// Global constants
const int HIGH = 99;
const int LOW = 10;

int main(int argc, char *argv[])
{
    // Set the random number seed
    srand(static_cast<int>(time(0)));

    // Declare variables
    const int SIZE = 20;
    int array[SIZE];
    int key;
    int found;

    // Fill array with random numbers, sort and print it
    fillArray(array, SIZE);
    selectionSort(array, SIZE);

    cout << "Sorted randomly generated array: " << endl << endl;
    printArray(array, SIZE);

    // Get random key to search for
    key = getRand();

    // Perform binary search
    cout << endl << "Performing binary search on value: " << key << endl
         << endl;
    found = binarySearch(array, SIZE, key);

    // Print if the value was found or not
    if (found != -1)
    {
        cout << "The value " << key << " was found at index: " << found << endl;
    }
    else 
    {
        cout << "The value " << key << " was not found" << endl;
    }

    return 0;
}

// Function to return a random number
int getRand()
{
    return rand() % (HIGH - LOW + 1) + LOW;
}

// Function to fill the array
void fillArray(int *array, int size)
{
    for (int index = 0; index < size; index++)
    {
        array[index] = getRand();
    }
}

// Function to print the array
void printArray(int *array, int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << array[index] << " ";
    }
    cout << endl;
}

void selectionSort(int *array, int size)
{
    // Declare variables
    int minIndex;
    int temp;

    // Perform sorting in ascending order
    for (int start = 0; start < size - 1; start++)
    {
        minIndex = start;
        for (int index = start + 1; index < size; index++)
        {
            if (array[index] < array[minIndex])
            {
                minIndex = index;
            }
        }

        // Swap the values
        temp = array[start];
        array[start] = array[minIndex];
        array[minIndex] = temp;
    }
}

// Function to perform binary search
int binarySearch(int *array, int size, int key)
{
    // Declare variables
    int high = size - 1;
    int low = 0;
    int middle;

    while (low <= high)
    {
        middle = (high + low) / 2;
        printArray(array, size);
        displayCursor(middle);

        if (array[middle] == key)
        {
            return middle;
        }
        else if (array[middle] < key)
        {
            low = middle + 1;
        }
        else 
        {
            high = middle - 1;
        }
    }

    return -1;
}

// Function to display current index
void displayCursor(int index)
{
    for (int count = 0; count < index * 3; count++)
    {
        cout << " ";
    }

    cout << "^" << endl;
}