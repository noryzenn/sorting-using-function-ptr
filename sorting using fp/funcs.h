#ifndef FUNCS_H
#define FUNCS_H

void resizeArray(int** arr, int* capacity, int newCapacity);
void addElement(int** arr, int* size, int* capacity); // calls resizeArray() if (size == capacity)
void setSortFunction(void (**sortFunction)(int*, int), void(*chosenFunc)(int*, int));
void sortArray(int* arr, int size, void(*sortFunction)(int*, int));


#endif
