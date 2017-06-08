#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_ENTRIES 10
#define MAX_LENGTH 20
#define CONFIG "examples/config"

/*
 * parse a config file with key value pairs and store the configuration inside a config struct
 * file format:
 * key1 = val1
 * key2 = val2
 * etc..
 */

struct config {
	char* keys[MAX_ENTRIES];
	char* vals[MAX_ENTRIES];
	int num_entries;
} conf;

void printConfig()
{
	printf("\nCONFIG: (%d entries)\n", conf.num_entries);
	printf("--------------------------------------\n");
	for (int i = 0; i < conf.num_entries; i++) 
	{
		printf("#%d key: %s, value: %s\n", i, conf.keys[i], conf.vals[i]);
	}
	printf("--------------------------------------\n");
}

int main(int argc, char* argv[])
{	
	FILE* fd;
	fd = fopen(CONFIG, "r");
	if (fd == NULL) {
		perror("error opening config file");
		exit(1);
	}
	
	// initialize config pointers
	for (int i = 0; i < MAX_ENTRIES; i++)
	{
		conf.vals[i] = malloc(MAX_LENGTH * sizeof(char));
		conf.keys[i] = malloc(MAX_LENGTH * sizeof(char));
	}
	
	// initialize temp vars
	char* key = malloc(MAX_LENGTH * sizeof(char));
	char* val = malloc(MAX_LENGTH * sizeof(char)); 
	
	// parse config
	printf("parsing config...\n");
	while (fscanf(fd, "%s = %s\n", key, val) != EOF) 
	{
		if (conf.num_entries == MAX_ENTRIES)
		{
			printf("MAX_ENTRIES reached!\n");
			break;
		}	
		strcpy(conf.keys[conf.num_entries], key);
		strcpy(conf.vals[conf.num_entries], val);
		conf.num_entries++;
		printf("found key: %s, val: %s, num_entries: %d\n", key, val, conf.num_entries);
	}
	
	free(val);
	free(key);
	fclose(fd);
	
	printConfig();
	
	return EXIT_SUCCESS;
}