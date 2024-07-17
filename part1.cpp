#include <iostream>
using namespace std;

//Part1:
// -----Create a Dynamic Array:
// Write a function createArray that takes an integer size and dynamically allocates an array of that
// size. The function returns a pointer to the newly created array.
int* createArray(int size) {
    int* newArrayPtr = new int[size]; // New Array is the pointer to the array created (address)
    return newArrayPtr;
}

// ------Initialize the Array:
// Write a function initializeArray that takes a pointer to an array and its size, then initializes the array
// with values from 0 to size-1.
void initializeArray(int* arrayPtr, int size) {
    for (int i = 0; i < size-1; i++) {
        arrayPtr[i] = i; // an array is just its first pointer address location
    }
}

//------- Print the Array:
// Write a function printArray that takes a pointer to an array and its size, and prints the elements of
// the array.
void printArray(int* arrayPtr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "\n " << arrayPtr[i]; // cout << arrayPtr would give the address, cout << *arrayPtr would give the value
                                     // in C++ cout << arrayPtr[i] ---> *(arrayPtr + i) so it does it under the hood
    }
}

// -------Delete the Array:
// Write a function deleteArray that takes a pointer to an array and deallocates the memory.
void deleteArray(int* arrayPtr) {
    delete[] arrayPtr;
}

// ------Main Function:
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // In the main function, use the above functions to:
    // Create a dynamic array of a size that is read from the user.
    int* myArray = createArray(size);

    // Initialize the array.
    initializeArray(myArray, size);

    // Print the array.
    printArray(myArray, size);

    // Delete the array
    deleteArray(myArray);

    return 0;
}
