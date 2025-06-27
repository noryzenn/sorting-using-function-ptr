#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "insertionSort.h"
#include "shellSort.h"

int main() {
	int size = 0;
	int capacity = 2;
	int user_choice; 
	int new_element;
	int newCapacity;
	int number_of_elements;
	int number_of_additional_elements;
	void (*func_ptr)(int*, int) = NULL;

	int* arr = malloc(sizeof(int) * capacity);
	printf("Enter the number of elements you want to add to the array: ");
	while (1) {
		if (scanf("%d", &number_of_elements) != 1) {
			printf("Invalid input. Please enter only positive integers.\n");
			while (getchar() != '\n');
			continue;
		}
		break;
	}
	for (int i = 0; i < number_of_elements; i++) {
		printf("Enter element %d: ", i + 1);
		scanf("%d", &new_element);
		addElement(&arr, &size, &capacity, new_element);
	}
	
	printf("\n\nChoose sorting method: \n");
	printf("1. Insertion Sort (Ascending)\n");
	printf("2. Shell Sort (Descending)\n");
	
	printf("Enter your choice: ");
	scanf("%d", &user_choice);

	if (user_choice == 1) {
		setSortFunction(&func_ptr, insertionSort);
	}
	else if (user_choice == 2) {
		setSortFunction(&func_ptr, shellSort);
	}
	else {
		printf("bad input lmao\n");
	}

	printf("\nArray before sorting: ");
	printArray(arr, size);
	
	sortArray(arr, size, func_ptr);

	printf("\nArray after sorting: ");
	printArray(arr, size);

	printf("\n\nResizing array to increase capacity...\n");
	resizeArray(&arr, &capacity, 2 * capacity);
	
	printf("Enter the number of additional elements you want to add: ");
	scanf("%d", &number_of_additional_elements);
	for (int i = number_of_elements; i < number_of_elements + number_of_additional_elements; i++) {
		printf("Enter element %d: ", i+1);
		scanf("%d", &new_element);
		addElement(&arr, &size, &capacity, new_element);
	}
	

	printf("\n\nChoose sorting method: \n");
	printf("1. Insertion Sort (Ascending)\n");
	printf("2. Shell Sort (Descending)\n");
	
	printf("Enter your choice: ");
	scanf("%d", &user_choice);

	if (user_choice == 1) {
		setSortFunction(&func_ptr, insertionSort);
	}
	else if (user_choice == 2) {
		setSortFunction(&func_ptr, shellSort);
	}
	else {
		printf("Congrats you managed to input something invalid again!!!!!!\n");
	}

	printf("\nArray before sorting: ");
	printArray(arr, size);

	sortArray(arr, size, func_ptr);
	
	printf("\nArray after sorting: ");
	printArray(arr, size);

	printf("\n\n\nThank you, hesenbeyy, for creating this masterpiece and the ones who get the honor to see this.\n\n\n");


	free(arr);
	return 0;
}	