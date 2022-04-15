#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sublist
{
    char *name;
    char *type;

    struct sublist *next;
};

struct symrec
{
    char *name;
    char *type;
    union
    {
        double var;
        double (*fnctptr)();
    } value;
    struct sublist *attributes;
    struct symrec *next;
};
typedef struct symrec symrec;
typedef struct sublist sublist;
void initialize(sublist *head)
{
    head = (sublist *)0;
}
symrec *sym_table = (symrec *)0;

symrec *putsym(char *sym_name, char *type)
{
    symrec *ptr;
    ptr = (symrec *)malloc(sizeof(symrec));
    ptr->name = (char *)malloc(strlen(sym_name) + 1);
    strcpy(ptr->name, sym_name);
    ptr->type = (char *)malloc(strlen(type) + 1);
    strcpy(ptr->type, type);
    ptr->next = (struct symrec *)sym_table;
    initialize(ptr->attributes);
    sym_table = ptr;
    return ptr;
}
symrec *getsym(char *sym_name)
{
    symrec *ptr;
    for (ptr = sym_table; ptr != (symrec *)0;
         ptr = (symrec *)ptr->next)
        if (strcmp(ptr->name, sym_name) == 0)
            return ptr;
    return 0;
}

sublist *getlist(char *sym_name)
{
    symrec *ptr;
    for (ptr = sym_table; ptr != (symrec *)0;
         ptr = (symrec *)ptr->next)
        if (strcmp(ptr->name, sym_name) == 0)
            return ptr->attributes;
    return 0;
}

sublist *put(char *sym, char *otype, sublist *head)
{
    sublist *ptr;
    ptr = (sublist *)malloc(sizeof(sublist));
    ptr->name = (char *)malloc(strlen(sym) + 1);
    ptr->type = (char *)malloc(strlen(otype) + 1);
    strcpy(ptr->name, sym);
    strcpy(ptr->type, otype);
    ptr->next = head;
    head = ptr;
    return ptr;
}
int *get(char *sym, char *otype, sublist *head)
{
    sublist *ptr;
    for (ptr = head; ptr != (sublist *)0; ptr = (sublist *)ptr->next)
    {
        if (strcmp(ptr->name, sym) == 0)
        {
            if (strcmp(ptr->type, otype) == 0)
                return 1;
        }
    }

    return 0;
}
