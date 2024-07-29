#include "linkedList.h"

struct Node* head;

void initLinkedList()
{
    head = malloc(1 * sizeof(struct Node));
    head->next = NULL;
}

void deleteLinkedList()
{
    if (head == NULL)
    {
        return;
    }

    if (head->next != NULL)
    {
        struct Node *ptr = head->next;
        struct Node *nextPtr;
        while(ptr->next != NULL)
        {
            nextPtr = ptr->next;
            free(ptr);
            ptr = nextPtr;
        }
        free(ptr);
    }
    free(head);
}

void insertFirst(int value)
{
    if (head == NULL)
    {
        initLinkedList();
    }
    
    struct Node *newNode = malloc(1 * sizeof(struct Node));
    newNode->value = value;
    newNode->next = head->next;

    head->next = newNode;
}

void insertAfter(int value, int offset)
{
    if (offset < 0)
    {
        deleteLinkedList();
        printf("Index out of bound!");
        exit(-1);
    }

    offset++;

    if (head == NULL)
    {
        initLinkedList();
    }

    if (offset == 0)
    {
        insertFirst(value);
        return;
    }
    else if (head->next == NULL)
    {
        deleteLinkedList();
        printf("Index out of bound!");
        exit(-1);
    }
    
    struct Node *newNode = malloc(1 * sizeof(struct Node));
    newNode->value = value;

    struct Node *ptr = head->next;
    for (size_t i = 1; i < offset; i++)
    {
        if (ptr->next == NULL)
        {
            deleteLinkedList();
            printf("Index out of bound!");
            exit(-1);
        }
        ptr = ptr->next;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

void insertLast(int value)
{
    if (head == NULL)
    {
        initLinkedList();
    }
    
    if (head->next == NULL)
    {
        insertFirst(value);
        return;
    }

    struct Node *newNode = malloc(1 * sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

int removeFirst()
{
    int value;

    if (head == NULL || head->next == NULL)
    {
        deleteLinkedList();
        printf("Index out of bound!");
        exit(-1);
    }
    
    value = head->next->value;
    struct Node *ptr = head->next;
    head->next = head->next->next;

    free(ptr);

    return value;
}

int removeAfter(int offset)
{
    int value;

    if (head == NULL || head->next == NULL || offset < 0)
    {
        deleteLinkedList();
        printf("Index out of bound!");
        exit(-1);
    }

    offset++;

    struct Node *ptr = head;
    struct Node *previousPtr;
    for (size_t i = 0; i < offset + 1; i++)
    {
        if (ptr->next == NULL)
        {
            deleteLinkedList();
            printf("Index out of bound!");
            exit(-1);
        }
        previousPtr = ptr;
        ptr = ptr->next;
    }

    previousPtr->next = ptr->next;

    value = ptr->value;
    free(ptr);

    return value;
}

int removeLast()
{
    int value;

    if (head == NULL || head->next == NULL)
    {
        deleteLinkedList();
        printf("Index out of bound!");
        exit(-1);
    }

    struct Node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    
    struct Node *oldPtr = ptr->next;
    ptr->next = NULL;

    value = oldPtr->value;
    free(oldPtr);

    return value;
}

int valueAt(int offset)
{
    if (offset < 0)
    {
        deleteLinkedList();
        printf("Index out of bound!");
        exit(-1);
    }

    if (head == NULL || head->next == NULL)
    {
        deleteLinkedList();
        printf("Index out of bound!");
        exit(-1);
    }

    offset++;

    struct Node *ptr = head;
    for (size_t i = 0; i < offset; i++)
    {
        if (ptr->next == NULL)
        {
            deleteLinkedList();
            printf("Index out of bound!");
            exit(-1);
        }
        ptr = ptr->next;
    }
    return ptr->value;
}

size_t length()
{
    if (head == NULL)
    {
        initLinkedList();
    }
    
    struct Node *ptr = head;
    size_t length = 0;
    while (ptr->next != NULL)
    {
        length++;
        ptr = ptr->next;
    }
    
    return length;
}

void printLinkedList()
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    struct Node *ptr = head->next;
    int counter = 0;
    while (ptr->next != NULL)
    {
        printf("At %d: %d\n", counter, ptr->value);
        counter++;
        ptr = ptr->next;
    }
    printf("At %d: %d\n", counter, ptr->value);
}