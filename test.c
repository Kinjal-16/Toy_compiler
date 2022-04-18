#include "intable.h"
int main()
{
    // Start with the empty list
    struct intable *head = NULL;

    putable("s", "int", head);
    putable("gh", "int", head);
    char *key = "s"; // key to delete

    printf("Created Linked List: ");
    displayList(head);

    // Function call
    for (int i = 0; i < 2; i++)
    {

        getable(&head, key);
    }

    displayList(head);
    return 0;
}