#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// generate and print 100 random numbers between 0-100.

int main(int argc, char *argv[]) 
{
	// seed with current time
	time_t t;
   	srand(time(&t));

	for (int i = 0; i < 100; i++)
	{
		// random number between 0 and 100
		int number = rand() % 101;
		printf("#%d: %d\n", i, number);
	}

    exit(EXIT_SUCCESS);
}
