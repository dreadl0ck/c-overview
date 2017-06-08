#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>

/*
 * fork the current process and establish an unnamed pipe between parent and child.
 * remember: always read to fd[0] and write to fd[1]
 */

int main(void) 
{
    char input[50] = "asdf";
    int input_size;

    int fd[2];
    if (pipe(fd) < 0) 
	{
        perror("Fehler beim erstellen der pipe!");
        return EXIT_FAILURE;
    }

    pid_t pid;
    if ((pid = fork()) < 0) 
	{
        perror("Fehler bei fork!");
        return EXIT_FAILURE;
    }

    switch (pid) 
	{
        case 0: // child
            printf("child PID: %d\n", getpid());
            close(fd[1]);
            input_size = read(fd[0], input, PIPE_BUF);
			
            if ((write(STDOUT_FILENO, input, input_size) != input_size)) 
			{
                perror("ERROR writing to stdout!");
                exit(EXIT_FAILURE);
            }
			
            puts("");
            break;
        default: // parent
            printf("parent PID: %d\n", getpid());
            close(fd[0]);
			
            puts("Please enter something to send to the child:");
            fgets(input, 50, stdin);
            
			input_size = sizeof(input) / sizeof(input[0]);
            printf("input size: %d\n", input_size);

            if ((write(fd[1], input, input_size)) != input_size) 
			{
                perror("Error writing string to pipe!");
                exit(EXIT_FAILURE);
            }
			
            if ((waitpid(pid, NULL, 0) < 0)) 
			{
                perror("Error waiting for child!");
                exit(EXIT_FAILURE);
            }
    }

    return EXIT_SUCCESS;
}
