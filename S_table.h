#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sublist
{
    char *name;
    char *type;
    char *scope;
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

symrec *putsym(char *sym_name, char *type, sublist *list)
{
    symrec *ptr;
    ptr = (symrec *)malloc(sizeof(symrec));
    ptr->name = (char *)malloc(strlen(sym_name) + 1);
    strcpy(ptr->name, sym_name);
    ptr->type = (char *)malloc(strlen(type) + 1);
    strcpy(ptr->type, type);
    ptr->next = (struct symrec *)sym_table;
    ptr->attributes = list;
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

sublist *put(char *sym, char *otype, sublist *head, char *scope)
{
    sublist *ptr;
    ptr = (sublist *)malloc(sizeof(sublist));
    ptr->name = (char *)malloc(strlen(sym) + 1);
    ptr->type = (char *)malloc(strlen(otype) + 1);

    ptr->scope = (char *)malloc(strlen(scope) + 1);

    // ptr->scope = scope;
    strcpy(ptr->name, sym);
    strcpy(ptr->type, otype);
    strcpy(ptr->scope, scope);
    ptr->next = (struct sublist *)head;
    head = ptr;
    return ptr;
}
int *get(char *sym, sublist *head)
{
    sublist *ptr;
    for (ptr = head; ptr != (sublist *)0; ptr = (sublist *)ptr->next)
    {
        if (strcmp(ptr->name, sym) == 0)
        {

            return 0;
        }
    }

    return 1;
}

void displayTable()
{
    symrec *ptr;
    for (ptr = sym_table; ptr != (symrec *)0; ptr = (symrec *)ptr->next)
    {
        sublist *j;
        printf(ptr->name);
        printf(":   ");
        for (j = ptr->attributes; j != (sublist *)0; j = (sublist *)j->next)
        {
            printf(j->scope);
            printf("-->");
        }
        printf("null");
        printf("\n");
    }
}
sublist *returnT(char *name, sublist *head)
{
    sublist *ptr;
    ptr = (sublist *)malloc(sizeof(sublist));
    ptr->name = (char *)malloc(strlen(name) + 1);
    ptr->type = (char *)malloc(strlen("return") + 1);
    strcpy(ptr->name, name);
    strcpy(ptr->type, "return");
    ptr->next = (struct sublist *)head;
    head = ptr;
    return ptr;
}
int checkReturn(char *name, sublist *head)
{
    sublist *ptr;
    for (ptr = head; ptr != (sublist *)0; ptr = (sublist *)ptr->next)
    {
        if (strcmp(ptr->type, "return") == 0)
        {
            if (strcmp(ptr->name, name) == 0)
                return 0;
        }
    }

    return 1;
}