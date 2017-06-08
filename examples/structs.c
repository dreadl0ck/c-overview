#include <stdlib.h>
#include <stdio.h>

struct mystruct {
    char *name;
    int count;
};

typedef struct {
    char *name;
    int count;
} mystruct2;

int main(void) 
{
    struct mystruct test;

    test.count = 1;
    test.name = "foo";

    printf("mystruct: count: %d, name: %s\n", test.count, test.name);

    mystruct2 test2;
    test2.count = 3;
    test2.name = "bar";

    printf("mystruct2: count: %d, name: %s\n", test2.count, test2.name);

    exit(EXIT_SUCCESS);
}
