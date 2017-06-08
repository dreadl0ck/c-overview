#include <stdlib.h>
#include <stdio.h>

int num1, num2;

int ggt(int x, int y) 
{	
	if (x < 0) {
		x = -x;
	}
	
	if (y < 0) {
		y = -y;
	}
	
	int c;
	while (y != 0) 
	{
		c = x % y;
		x = y;
		y = c;
		
	}
	return x;
}

int main(int argc, char* argv[]) 
{
	printf("argc: %d\n", argc);
	if (argc == 3) 
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		printf("ggT von %d und %d: %d\n", num1, num2, ggt(num1, num2));
	} else {
		printf("[ERROR] missing params!\n");
		printf("usage: ./ggT <num1> <num2>\n");
		exit(1);
	}
	
	return EXIT_SUCCESS;
}
