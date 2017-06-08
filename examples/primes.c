#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) 
{
    
	if (argc <= 1) 
	{
        puts("missing argument: need a number.");
        return EXIT_FAILURE;
    }
    unsigned long long prime = atoll(argv[1]);

    printf("number: %llu\n", prime);

    unsigned long long upper_bound, result;
    int i = 2;

    upper_bound = sqrtl(prime);
    printf("upper_bound: %llu\n", upper_bound);

    while (i <= upper_bound) 
	{

        //printf("debug i: %d\n",i);

        // check if i is odd
        if (i % 2 || i == 2) 
		{
            result = (prime % i);

            printf("result: %llu\n",result);

            if (result == 0) 
			{
                puts("Not a prime!");
                break;
            }
        }
        i++;
    }

    if (i > upper_bound) 
	{
        printf("%llu is a prime number!\n", prime);
    }
    return EXIT_SUCCESS;
}
