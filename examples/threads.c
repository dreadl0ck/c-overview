#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *printHello(void *threadid) 
{	
    long tid;
    tid = (long)threadid;

    printf("Hello from Thread number: %ld\n", tid);
    pthread_exit(NULL);
}

int main(void) 
{
    pthread_t threads[NUM_THREADS];

    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) 
	{
		
        printf("creating thread %ld\n", t);

        rc = pthread_create(&threads[t], NULL, printHello, (void*)t);

        if (rc) {
            printf("ERROR: return code from pthread_create is %d", rc);
            exit(1);
        }
    }

    pthread_exit(NULL);
}
