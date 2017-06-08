#include <stdlib.h>
#include <stdio.h>

// read commandline arguments and store them into a string array 

int main(int argc, char *argv[]) 
{   
	if (argc < 2) 
	{
        puts("no arguments");
        exit(1);
    }
	
	char* args[argc];
	printf("found %d arguments.\n", argc);
	
	// iterate over argv and copy pointers to args array
	for (int i = 0; i < argc; i++) 
	{
		printf("arg%d: %s\n", i, argv[i]);
		args[i] = argv[i];
	}
	
	// iterate over args array
	for (int i = 0; i < argc; i++) 
	{
		printf("stored arg%d: %s\n", i, args[i]);
	}
	
	return EXIT_SUCCESS;
}
