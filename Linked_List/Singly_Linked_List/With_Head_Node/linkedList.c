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

void insert(Node *head, int value)
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

void removeLL(Node *head)
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
    
    Node *ptr = head->next;
    head->next = head->next->next;
    free(ptr);
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

    Node *ptr = head->next;
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
        deleteLinkedList(head);
        exit(-1);
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

    printf("head");
    printf(" -> header");
    Node *ptr = head->next;
    while (ptr != NULL)
    {
        printf(" -> %d", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}