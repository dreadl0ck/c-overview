#include <stdlib.h>
#include <stdio.h>

// sort an integer array with quicksort

// need a global var to store the array size.
// calculating the array size inside printArray does not work,
// because calculating the size of a pointer to an array is not possible in c!
int array_size;

int comparefunc(const void* x, const void* y)
{
	return (*(int*)x - *(int*)y);
}

void printArray(int* array)
{	
	printf("[%d", array[0]);
	for (int i = 1; i < array_size; i++)
	{
		printf(", %d", array[i]);
	}
	puts("]");
}

int main(void)
{
	int array[] = {1234, 23432, 434, 234, 543, 2344, 434, 13, 42};
	array_size = sizeof(array) / sizeof(int);
	printf("array size: %d\n", array_size);
	
	printf("array before sort: ");
	printArray(array);
	
	// sort with quicksort algo
	qsort(array, sizeof(array) / sizeof(int), sizeof(int), comparefunc);
	
	printf("array after sort: ");
	printArray(array);
	
	return EXIT_SUCCESS;	
}
