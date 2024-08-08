#include "linkedList.h"

Node *initLinkedList(int value)
{
    Node *head = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for Linked List structure failed!\n");
        exit(-1);
    }

    head->value = value;
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

Node *insert(Node *head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for new Node failed!\n");
        deleteLinkedList(head);
        exit(-1);
    }

    newNode->value = value;
    newNode->next = head;

    return newNode;
}

Node *removeLL(Node *head)
{
    if (head == NULL)
    {
        printf("No elements in the Linked List!\n");
        return head;
    }
    
    Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

int valueAt(Node *head, int offset)
{
    if (head == NULL)
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

    if (ptr == NULL || counter > offset)
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
        return 0;
    }
    
    Node *ptr = head;
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
        printf("The Linked List was empty!\n");
        return;
    }

    printf("head");
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf(" -> %d", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}