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
        free(linkedList);
        exit(-1);
    }

    head->value = value;
    head->next = NULL;
    
    linkedList->head = head;

    return linkedList;
}

void deleteLinkedList(LinkedList *linkedList)
{
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
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

void insert(LinkedList *linkedList, int value)
{
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

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
    while (ptr != NULL)
    {
        if (counter == offset)
        {
            break;
        }
        ptr = ptr->next;
        counter++;
    }

    if (ptr == NULL)
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

    Node *ptr = linkedList->head;
    size_t length = 0;
    while (ptr != NULL)
    {
        length++;
        ptr = ptr->next;
    }
    
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
    while (ptr != NULL)
    {
        printf(" -> %d", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}