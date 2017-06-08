#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

int main(int argc, char *argv[]) 
{
    // get string from stdin
    char string[50];
    puts("Please enter something");
    fgets(string, 50, stdin);

    // concatenate strings
    char string2[] = "YOU MAD!";
    strcat(string, string2);

    puts(string);

    // compare strings
    char str1[] = "aaXaa";
    char str2[] = "aaYaa";

    // vergleiche str1 mit str2, X < Y, also <0
    printf("Vergleich str1 mit str2: %d\n", strcmp(str1, str2));

    // vergleiche str2 mit str1, Y > X, also >0
    printf("Vergleich str2 mit str1: %d\n", strcmp(str2, str1));

    // setze Strings gleich
    strcpy(str2, str1);

    if(strcmp(str1, str2) == 0) {
    	printf("str1 ist gleich str2!\n");
    }

    // get length
    printf("strlen(str1): %lu\n", strlen(str1));

    // split by delimiter
    char test_string[] = "asdfad,23,tgh";
    char *tok = strtok(test_string, ",");

    while (tok != NULL) {
        printf("Abschnitt: %s\n", tok);
        tok = strtok(NULL, ",");
    }
	
	char substring[] = "Xa";
	
	// check for existence of substring
	if (strstr(str1, substring) != NULL)
	{
		printf("%s contains %s\n", str1, substring);
	}

    exit(0);
}
