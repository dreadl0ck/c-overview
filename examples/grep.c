#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

// stupid grep that reads from stdin and filters all lines which contain the keyword

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		puts("missing arg.");
		exit(1);
	}
	
	puts("reading from stdin...");
	char* line = malloc(100 * sizeof(char));
	
	while (fgets(line, 100, stdin) != NULL)
	{
		if (strstr(line, argv[1]) != NULL)
		{
			printf("%s", line);
		}
	}
	
	return EXIT_SUCCESS;
}
