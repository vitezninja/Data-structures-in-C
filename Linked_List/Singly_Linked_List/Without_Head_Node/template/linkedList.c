#include "linkedList.h"

LinkedList *initLinkedList()
{
    LinkedList *linkedList = (LinkedList *)malloc(sizeof(LinkedList));
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for Linked List structure failed!\n");
        return NULL;
    }

    linkedList->head = NULL;
    linkedList->length = 0;

    return linkedList;
}

void deleteLinkedList(LinkedList *linkedList)
{
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        return;
    }

    Node *ptr = linkedList->head;
    Node *nextPtr;
    while(ptr != NULL)
    {
        nextPtr = ptr->next;
        free(ptr);
        ptr = nextPtr;
    }
    free(linkedList);
}

size_t length(LinkedList *linkedList)
{
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        return 0;
    }

    return linkedList->length;
}