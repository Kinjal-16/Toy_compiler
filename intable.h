#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct intable
{
    char *name;
    char *type;

    struct intable *next;
};


typedef struct sublist intable;

intable *intable = (intable *)0;

symrec *putable(char *sym_name, char *type)
{
    intable *ptr;
    ptr = (intable *)malloc(sizeof(intable));
    ptr->name = (char *)malloc(strlen(sym_name) + 1);
    strcpy(ptr->name, sym_name);
    ptr->type = (char *)malloc(strlen(type) + 1);
    strcpy(ptr->type, type);
    ptr->next = (struct intable *)intable;
    intable = ptr;
    return ptr;
}
symrec *gettable(char *sym_name,char *type)
{
    intable *ptr;
    for (ptr = intable; ptr != (intable *)0;
         ptr = (intable *)ptr->next)
        if (strcmp(ptr->name, sym_name) == 0 && strcmp(ptr->type,type)==0)
            
            return ptr;
    return 0;
}
