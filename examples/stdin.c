#include <stdio.h>
#include <stdlib.h>

// read stuff from stdin

int main()
{
	char str[50];
	//char *str = malloc(50);

	printf("enter a string: ");
	fgets(str, 50, stdin);

	printf("you entered: %s\n", str);

	printf("enter a character: ");
	int c = getc(stdin);
	
	printf("you entered %c\n", (char)c);
	
	printf("enter a string, which can be converted to an integer: ");
	scanf("%s", str);
	
	while (atoi(str) == 0)
	{
		printf("thats not an integer, dummy! try again: ");
		scanf("%s", str);
	}
	
	printf("you entered: %d\n", atoi(str));

	return EXIT_SUCCESS;
}
