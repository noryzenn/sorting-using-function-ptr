#include <stdio.h>
#include "insertionSort.h"
#include "shellSort.h"

void resizeArray(int** arr, int* capacity, int newCapacity);
void addElement(int** arr, int* size, int* capacity, int value); // calls resizeArray() if (size == capacity)
void setSortFunction(void (**sortFunction)(int*, int), void(*chosenFunc)(int*, int));
void sortArray(int* arr, int size, void(*sortFunction)(int*, int));