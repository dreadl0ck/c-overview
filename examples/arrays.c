#include <stdlib.h>
#include <stdio.h>

void printMatrix(int matrix[5][5]) 
{
	for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("[%d]", matrix[i][j]);
        }
		puts("");
    }
}

int main() 
{
	// declare and initialize
	int integers[] = {1, 45, 67, 15, 25, 21};
    char chars[] = {'a', 'b','c'};
	char* strings[] = {"some", "random", "stuff", "in", "here"};

    printf("size of char array: %d\n", (int)(sizeof(chars) / sizeof(char)));
    printf("size of integer array: %d\n", (int)(sizeof(integers) / sizeof(int)));
	printf("size of string array: %d\n", (int)(sizeof(strings) / sizeof(char*)));
	
	printf("two dimensional matrix:\n");
    int matrix[5][5] = { 0 };
	printMatrix(matrix);
	
	printf("changing some values...\n");
	matrix[1][1] = 7;
	matrix[1][2] = 3;
	matrix[3][5] = 9;
	matrix[4][3] = 5;
	matrix[1][4] = 2;
	matrix[2][2] = 6;
	matrix[2][1] = 1;
	
	printMatrix(matrix);

    return EXIT_SUCCESS;
}
