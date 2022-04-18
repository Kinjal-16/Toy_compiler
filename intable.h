#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct intable
{
    char *name;
    char *type;

    struct intable *next;
};

typedef struct intable intable;

intable *table = (intable *)0;

intable *putable(char *sym_name, char *type, intable *list)
{
    intable *ptr;
    ptr = (intable *)malloc(sizeof(intable));
    ptr->name = (char *)malloc(strlen(sym_name) + 1);
    strcpy(ptr->name, sym_name);
    ptr->type = (char *)malloc(strlen(type) + 1);
    strcpy(ptr->type, type);
    ptr->next = (struct intable *)list;
    list = ptr;
    return ptr;
}
intable *getable(intable *head_ref, char *key)
{
    printf("stable here");

    struct intable *temp = head_ref, *prev;

    while (temp != NULL && strcmp(temp->name, key) == 0)
    {
        head_ref = temp->next;
        free(temp);
        temp = head_ref;
    }

    while (temp != NULL)
    {

        while (temp != NULL && strcmp(temp->name, key) != 0)
        {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in linked list
        if (temp == NULL)
            return NULL;

        prev->next = temp->next;

        free(temp); // Free memory

        // Update Temp for next iteration of outer loop
        temp = prev->next;
    }
    return head_ref;
}
void displayList(intable *stnode)
{
    struct intable *tmp;
    if (stnode == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = stnode;
        while (tmp != NULL)
        {
            printf(" Data = %s\n", tmp->name); // prints the data of current node
            tmp = tmp->next;                   // advances the position of current node
        }
    }
}
