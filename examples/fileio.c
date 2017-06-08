#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{

    // open file for writing
    FILE* fd;
    fd = fopen("test.txt", "w+");
	if (fd == NULL)
	{
		perror("error opening file for writing:");
		exit(1);
	}

    // write string to file
    int result = fputs("bla\n", fd);
    printf("result: %d\n", result);

    // print format string to file
    fprintf(fd, "bla %d\n", 1);

    // close file to flush buffer
    fclose(fd);

    // reopen file for reading
    fd = fopen("test.txt", "r");
	if (fd == NULL)
	{
		perror("error opening file for reading:");
		exit(1);
	}
	
	// print file content
    char line[10];
    puts("File content:");
    while (fgets(line, 10, fd) != NULL) 
	{
        printf("%s", line);
    }

    exit(EXIT_SUCCESS);
}
