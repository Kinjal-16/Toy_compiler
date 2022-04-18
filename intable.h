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
intable *gettable(char *sym_name, char *type, intable *list)
{
    intable *ptr;
    intable *pre;
    int i = 0;
    for (ptr = list; ptr != (intable *)0; ptr = (intable *)ptr->next)
    {
        i++;
        if (i > 1)
        {
            if (strcmp(ptr->name, sym_name) == 0)
            {
                if (strcmp(ptr->type, type) == 0)
                {
                    pre->next = ptr->next;
                    free(ptr);
                    return list;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            if (strcmp(ptr->name, sym_name) == 0)
            {
                if (strcmp(ptr->type, type) == 0)
                {

                    list = ptr->next;
                    free(ptr);
                }
            }

            pre = ptr;
        }
        return 0;
    }
