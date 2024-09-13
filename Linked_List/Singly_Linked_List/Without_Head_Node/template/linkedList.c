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

void removeLL(LinkedList *linkedList)
{
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        return;
    }

    if (linkedList->head == NULL)
    {
        fprintf(stderr, "ERROR: No elements in the Linked List!\n");
        return;
    }

    Node *ptr = linkedList->head;
    linkedList->head = ptr->next;
    free(ptr);
    linkedList->length--;
}

Node *pop(LinkedList *linkedList)
{
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        return NULL;
    }

    if (linkedList->head == NULL)
    {
        fprintf(stderr, "ERROR: No elements in the Linked List!\n");
        return NULL;
    }

    Node *ptr = linkedList->head;
    linkedList->head = ptr->next;
    ptr->next = NULL;
    linkedList->length--;

    return ptr;
}

void removeAt(LinkedList *linkedList, int index)
{
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        return;
    }

    if (linkedList->head == NULL)
    {
        fprintf(stderr, "ERROR: No elements in the Linked List!\n");
        return;
    }

    if (index < 0)
    {
        fprintf(stderr, "ERROR: Index out of bound!\n");
        return;
    }

    Node *ptr = linkedList->head;
    int counter = 0;
    while (ptr != NULL)
    {
        if (counter == index - 1)
        {
            break;
        }
        ptr = ptr->next;
        counter++;
    }

    if (ptr == NULL || ptr->next == NULL)
    {
        fprintf(stderr, "ERROR: Index out of bound!\n");
        return;
    }

    Node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    linkedList->length--;
}

Node *popAt(LinkedList *linkedList, int index)
{
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        return NULL;
    }

    if (linkedList->head == NULL)
    {
        fprintf(stderr, "ERROR: No elements in the Linked List!\n");
        return NULL;
    }

    if (index < 0)
    {
        fprintf(stderr, "ERROR: Index out of bound!\n");
        return NULL;
    }

    Node *ptr = linkedList->head;
    int counter = 0;
    while (ptr != NULL)
    {
        if (counter == index - 1)
        {
            break;
        }
        ptr = ptr->next;
        counter++;
    }

    if (ptr == NULL || ptr->next == NULL)
    {
        fprintf(stderr, "ERROR: Index out of bound!\n");
        return NULL;
    }

    Node *temp = ptr->next;
    ptr->next = temp->next;
    temp->next = NULL;
    linkedList->length--;

    return temp;
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