#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) 
{
    if (argc < 2) 
	{
        puts("no argument supplied!");
        return EXIT_FAILURE;
    }

	// open file for reading
    FILE* fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		perror("error opening file for reading:");
		exit(1);
	}
    
	// char line[100];
	char *line = malloc(100 * sizeof(char));
	
	// read file line by line
	while (fgets(line, 100, fd) != NULL)
	{
		printf("%s", line);
	}
	
	free(line);
    fclose(fd);
    return EXIT_SUCCESS;
}
