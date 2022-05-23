/*
    Anthony Mendez
    05/22/22
    Linear Search

    This program creates a random array and performs linear search
    with a random key
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

// Function prototypes
int getRand();
void fillArray(int *array, int size);
void printArray(int *array, int size);
int linearSearch(int *array, int size, int key);
void displayCursor(int index);

// Global Constants
const int HIGH = 99;
const int LOW = 10;

int main()
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    // Declare variables
    const int SIZE = 20;
    int array[SIZE];
    int key;
    int found;

    // Fill array with random numbers
    fillArray(array, SIZE);
    
    // Display the current array
    cout << "Random generated array:" << endl << endl;
    printArray(array, SIZE);

    // Generate a random key to search the array
    key = getRand();

    // Perform linear search
    found = linearSearch(array, SIZE, key);

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

// Function to get random number
int getRand()
{
    return rand() % (HIGH - LOW + 1) + LOW;
}

// Function to fill array with random numbers
void fillArray(int *array, int size)
{
    for (int index = 0; index < size; index++)
    {
        array[index] = getRand();
    }
}

// Function to display the array
void printArray(int *array, int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << array[index] << " ";
    }
    cout << endl;
}

// Linear search to find value within array
int linearSearch(int *array, int size, int key)
{
    cout << endl << "Performing linear search on value: " << key << endl << endl;

    for (int index = 0; index < size; index++)
    {
        printArray(array, size);
        displayCursor(index);

        if (array[index] == key)
        {
            return index;
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