#include "linkedList.h"

Node *initLinkedList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for Linked List structure failed!\n");
        exit(-1);
    }

    head->next = NULL;
    return head;
}

void deleteLinkedList(Node *head)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    Node *ptr = head;
    Node *nextPtr;
    while(ptr != NULL)
    {
        nextPtr = ptr->next;
        free(ptr);
        ptr = nextPtr;
    }
}

void insertFirst(Node *head, int value)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }
    
    Node *newNode = (Node *)malloc(sizeof(Node));
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

void insertAfter(Node *head, int value, int offset)
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

    Node *ptr = head;
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

    Node *newNode = (Node *)malloc(sizeof(Node));
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

void insertLast(Node *head, int value)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for new Node failed!\n");
        deleteLinkedList(head);
        exit(-1);
    }

    newNode->value = value;
    newNode->next = NULL;

    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

int removeFirst(Node *head)
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
    Node *ptr = head->next;
    head->next = head->next->next;
    free(ptr);

    return value;
}

int removeAfter(Node *head, int offset)
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

    Node *ptr = head;
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

    Node *toDelete = ptr->next;
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

int removeLast(Node *head)
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

    Node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    
    Node *oldPtr = ptr->next;
    int value = oldPtr->value;
    ptr->next = NULL;
    free(oldPtr);

    return value;
}

int valueAt(Node *head, int offset)
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

    Node *ptr = head;
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

size_t length(Node *head)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }
    
    Node *ptr = head->next;
    size_t length = 0;
    while (ptr != NULL)
    {
        length++;
        ptr = ptr->next;
    }
    
    return length;
}

void printLinkedList(Node *head)
{
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    if (head->next == NULL)
    {
        printf("The Linked List was empty!\n");
        return;
    }

    Node *ptr = head->next;
    int counter = 0;
    while (ptr != NULL)
    {
        printf("At %d: %d\n", counter, ptr->value);
        counter++;
        ptr = ptr->next;
    }
}