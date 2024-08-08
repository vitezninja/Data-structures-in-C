#include "linkedList.h"

LinkedList *initLinkedList(int value)
{
    LinkedList *linkedList = (LinkedList *)malloc(sizeof(LinkedList));
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for Linked List structure failed!\n");
        exit(-1);
    }

    Node *head = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for Linked List head failed!\n");
        exit(-1);
    }

    head->value = value;
    head->next = head;

    linkedList->head = head;
    linkedList->last = head;

    return linkedList;
}

void deleteLinkedList(LinkedList *linkedList)
{
    if (linkedList == NULL || linkedList->head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    Node *ptr = linkedList->head;
    Node *nextPtr;
    while(ptr != linkedList->last)
    {
        nextPtr = ptr->next;
        free(ptr);
        ptr = nextPtr;
    }
    free(ptr);
    free(linkedList);
}

void insert(LinkedList *linkedList, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for new Node failed!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }

    newNode->value = value;
    newNode->next = linkedList->head;

    linkedList->head = newNode;
    linkedList->last->next = linkedList->head;
}

void removeLL(LinkedList *linkedList)
{
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    if (linkedList->head == NULL)
    {
        printf("No elements in the Linked List!\n");
        return;
    }
    
    Node *ptr = linkedList->head;
    linkedList->head = linkedList->head->next;
    linkedList->last->next = linkedList->head;
    free(ptr);
}

int valueAt(LinkedList *linkedList, int offset)
{
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    if (linkedList->head == NULL)
    {
        fprintf(stderr, "ERROR: No elements in the Linked List!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }

    if (offset < 0)
    {
        fprintf(stderr, "ERROR: Index out of bound!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }

    Node *ptr = linkedList->head;
    int counter = 0;
    while (ptr != linkedList->last)
    {
        if (counter == offset)
        {
            break;
        }
        ptr = ptr->next;
        counter++;
    }

    if (counter != offset)
    {
        fprintf(stderr, "ERROR: Index out of bound!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }

    return ptr->value;
}

size_t length(LinkedList *linkedList)
{
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    if (linkedList->head == NULL)
    {
        return 0;
    }
    
    Node *ptr = linkedList->head;
    size_t length = 0;
    while (ptr != linkedList->last)
    {
        length++;
        ptr = ptr->next;
    }
    length++;
    
    return length;
}

void printLinkedList(LinkedList *linkedList)
{
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    if (linkedList->head == NULL)
    {
        printf("The Linked List was empty!\n");
        return;
    }

    printf("head");
    Node *ptr = linkedList->head;
    while (ptr != linkedList->last)
    {
        printf(" -> %d", ptr->value);
        ptr = ptr->next;
    }
    printf(" -> %d -> head", ptr->value);
    printf("\n");
}