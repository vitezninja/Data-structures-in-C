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
    head->previous = NULL;
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
    newNode->previous = NULL;
    newNode->next = linkedList->head;
    //If the Linked List is empty head is NULL
    if (linkedList->head != NULL)
    {
        linkedList->head->previous = newNode;
    }

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
    //If the Linked List is only had 1 element then after removal head is NULL
    if (linkedList->head != NULL)
    {
        linkedList->head->previous = NULL;
    }
    
    free(ptr);
}

int valueAt(LinkedList *linkedList, int index)
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

    if (index < 0)
    {
        fprintf(stderr, "ERROR: Index out of bound!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }

    Node *ptr = linkedList->head;
    int counter = 0;
    while (ptr != NULL)
    {
        if (counter == index)
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

void print(LinkedList *linkedList)
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
    int isFirst = 1;
    while (ptr != NULL)
    {   
        if (isFirst)
        {
            printf(" -> ");
            isFirst = 0;
        }
        else
        {
            printf(" <--> ");
        }
        printf("%d", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

void debug(LinkedList *linkedList)
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

    int index = 0;
    Node *ptr = linkedList->head;
    while (ptr != NULL)
    {   
        printf("%d. index:\n", index);
        printf("address: %d, ", ptr);
        printf("value: %d, ", ptr->value);
        if (ptr->previous == NULL)
        {
            printf("previous address: NULL ");
        }
        else
        {
            printf("previous address: %d ", ptr->previous);
        }

        if (ptr->next == NULL)
        {
            printf("next address: NULL\n");
        }
        else
        {
            printf("next address: %d\n", ptr->next);
        }
        ptr = ptr->next;
        index++;
    }
}