#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
 * calculate the first n fibonacci numbers
 * and return the result as pointer to an integer array
 */

const int n = 20;

// iterative implementierung
// long fibonacci_it(long x) 
// {
    
// 	long f0, f1, tmp, i;
//     f0 = 0;
//     f1 = 1;

//     if (x <= 1) 
// 	{
//         return x;
//     }

//     for (i = 2; i < x; ++i) 
// 	{
//         tmp = f1;
//         f1 = f0 + f1;
//         f0 = tmp;
//     }

//     return f1;
// }

// _fib(10) = ....
int _fib(int n) 
{	
    if (n <= 1) 
	{
        return n;
    }
    return _fib(n-1) + _fib(n-2);
}

// fib(10) = int[10] {0,1,1,2,3,5,8,13,21,34};
int* fib(int n) 
{	
    int i; 
	int* f = malloc(n * sizeof(int*));

    for (i=0; i <= n; i++) 
	{
        f[i] = _fib(i);
    }
    return f;
}

int main(int argc, char *argv[]) 
{	
    int i, *res = fib(n);

    for(i=0; i <= n; i++) 
	{
        printf("fib %d = %d\n", i, res[i]);
    }

    free(res);
    return EXIT_SUCCESS;
}
