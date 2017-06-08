#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// Singly-linked list

struct node 
{
    int x;
    struct node *next;
};

// using pointers
void v1() 
{
    struct node* list = malloc(sizeof(struct node));
    struct node* elem = malloc(sizeof(struct node));

    elem->x = 0;
    elem->next = NULL;

    list->x = 1;
    list->next = elem;

    puts("added elem to list.");
    //printf("list.next: %x \n", list->next);

    struct node* currentElem = list;
    int count = 0;
    while (currentElem->next != NULL) {
        count++;
        currentElem = currentElem->next;
    }

    printf("Found %d elements in list!\n", count);
}
