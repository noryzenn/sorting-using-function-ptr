#include <stdio.h>
#include "insertionSort.h"

void insertionSort(int* arr, int size) {
	int temp;
	for (int i = 1; i < size; i++) {
		int j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j -= 1;
		}
	}
}