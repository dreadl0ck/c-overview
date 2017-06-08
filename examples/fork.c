#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// fork the current process and print child and parent PIDs

int main(int argc, char *argv[]) 
{
    if (argc < 1) 
	{
        perror("missing argument!");
        exit(EXIT_FAILURE);
    }

    printf("parent PID before fork: %d\n", getpid());

    int cpid = fork();
    switch (cpid) 
	{
        case -1:
            perror("error forking!");
            exit(EXIT_FAILURE);
        case 0:
            printf("Child PID: %d\n", getpid());
            return 0;
        default:
            printf("Parent PID: %d\n", getpid());
            return 0;
    }

    exit(EXIT_SUCCESS);
}
