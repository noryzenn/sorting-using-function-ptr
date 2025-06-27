#include <stdio.h>
#include <stdlib.h>
#include "insertionSort.h"
#include "shellSort.h"

void resizeArray(int** arr, int* capacity, int newCapacity) {
	if (*capacity == newCapacity) return;
	int* temp = realloc(*arr, newCapacity*sizeof(int));
	if (!temp) {
		printf("Error. Realloc fails.\n");
		exit(1);
	}
	*arr = temp;
	*capacity = newCapacity;
}
void addElement(int** arr, int* size, int* capacity, int value) {
	if (*size == *capacity) {
		resizeArray(arr, capacity, (*capacity) * 2);
	}
	(*arr)[*size] = value;
	(*size)++;
}

void setSortFunction(void (**sortFunction)(int*, int), void(*chosenFunc)(int*, int)) {
	*sortFunction = chosenFunc;
}

void sortArray(int* arr, int size, void(*sortFunction)(int*, int)) {
	if (sortFunction == NULL) {
		printf("Error. Sorting Function not set.\n");
	}
	else {
		sortFunction(arr, size);
	}
}

void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}