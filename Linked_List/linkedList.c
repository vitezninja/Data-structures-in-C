#include "linkedList.h"

struct Node *initLinkedList()
{
    struct Node *head = malloc(1 * sizeof(struct Node));
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for Linked List structure failed!\n");
        exit(-1);
    }

    head->next = NULL;
    return head;
}

void deleteLinkedList(struct Node *head)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    struct Node *ptr = head;
    struct Node *nextPtr;
    while(ptr != NULL)
    {
        nextPtr = ptr->next;
        free(ptr);
        ptr = nextPtr;
    }
}

void insertFirst(struct Node *head, int value)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }
    
    struct Node *newNode = malloc(1 * sizeof(struct Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for new Node failed!\n");
        deleteLinkedList(head);
        exit(-1);
    }

    newNode->value = value;
    newNode->next = head->next;
    head->next = newNode;
}

void insertAfter(struct Node *head, int value, int offset)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }
    else if (offset < 0)
    {
        fprintf(stderr, "ERROR: Index out of bound!\n");
        deleteLinkedList(head);
        exit(-1);
    }

    struct Node *ptr = head;
    for (size_t i = 0; i <= offset; i++)
    {
        if (ptr->next == NULL)
        {
            fprintf(stderr, "ERROR: Index out of bound!\n");
            deleteLinkedList(head);
            exit(-1);
        }
        ptr = ptr->next;
    }

    struct Node *newNode = malloc(1 * sizeof(struct Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for new Node failed!\n");
        deleteLinkedList(head);
        exit(-1);
    }

    newNode->value = value;
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void insertLast(struct Node *head, int value)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    struct Node *newNode = malloc(1 * sizeof(struct Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for new Node failed!\n");
        deleteLinkedList(head);
        exit(-1);
    }

    newNode->value = value;
    newNode->next = NULL;

    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

int removeFirst(struct Node *head)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    if (head->next == NULL)
    {
        fprintf(stderr, "ERROR: No elements in the Linked List!\n");
        deleteLinkedList(head);
        exit(-1);
    }
    
    int value = head->next->value;
    struct Node *ptr = head->next;
    head->next = head->next->next;
    free(ptr);

    return value;
}

int removeAfter(struct Node *head, int offset)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    if (head->next == NULL)
    {
        fprintf(stderr, "ERROR: No elements in the Linked List!\n");
        deleteLinkedList(head);
        exit(-1);
    }

    if (offset < 0)
    {
        fprintf(stderr, "ERROR: Index out of bound!\n");
        deleteLinkedList(head);
        exit(-1);
    }

    struct Node *ptr = head;
    for (size_t i = 0; i <= offset; i++)
    {
        if (ptr->next == NULL)
        {
            fprintf(stderr, "ERROR: Index out of bound!\n");
            deleteLinkedList(head);
            exit(-1);
        }
        ptr = ptr->next;
    }

    struct Node *toDelete = ptr->next;
    if (toDelete == NULL)
    {
        fprintf(stderr, "ERROR: No element to remove after the given offset!\n");
        deleteLinkedList(head);
        exit(-1);
    }

    int value = toDelete->value;
    ptr->next = toDelete->next;
    free(toDelete);

    return value;
}

int removeLast(struct Node *head)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    if (head->next == NULL)
    {
        fprintf(stderr, "ERROR: No elements in the Linked List!\n");
        deleteLinkedList(head);
        exit(-1);
    }

    struct Node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    
    struct Node *oldPtr = ptr->next;
    int value = oldPtr->value;
    ptr->next = NULL;
    free(oldPtr);

    return value;
}

int valueAt(struct Node *head, int offset)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    if (head->next == NULL)
    {
        fprintf(stderr, "ERROR: No elements in the Linked List!\n");
        deleteLinkedList(head);
        exit(-1);
    }

    if (offset < 0)
    {
        fprintf(stderr, "ERROR: Index out of bound!\n");
        deleteLinkedList(head);
        exit(-1);
    }

    struct Node *ptr = head;
    for (size_t i = 0; i <= offset; i++)
    {
        if (ptr->next == NULL)
        {
            fprintf(stderr, "ERROR: Index out of bound!\n");
            deleteLinkedList(head);
            exit(-1);
        }
        ptr = ptr->next;
    }
    return ptr->value;
}

size_t length(struct Node *head)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }
    
    struct Node *ptr = head->next;
    size_t length = 0;
    while (ptr != NULL)
    {
        length++;
        ptr = ptr->next;
    }
    
    return length;
}

void printLinkedList(struct Node *head)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    struct Node *ptr = head->next;
    int counter = 0;
    while (ptr != NULL)
    {
        printf("At %d: %d\n", counter, ptr->value);
        counter++;
        ptr = ptr->next;
    }
}