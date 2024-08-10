#include "linkedList.h"

LinkedList *initLinkedList()
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

    head->previous = head;
    head->next = head;

    linkedList->head = head;
    linkedList->last = head;

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
    if (linkedList == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    if (linkedList->head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        deleteLinkedList(linkedList);
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
    newNode->previous = linkedList->head;
    newNode->next = linkedList->head->next;

    linkedList->head->next->previous = newNode;
    linkedList->head->next = newNode;
    if (linkedList->last == linkedList->head)
    {
        linkedList->last = linkedList->head->next;
        linkedList->head->previous = linkedList->last;
    }
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
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }

    if (linkedList->head->next == linkedList->head)
    {
        printf("No elements in the Linked List!\n");
        return;
    }
    
    Node *ptr = linkedList->head->next;
    linkedList->head->next = linkedList->head->next->next;

    if (linkedList->head == linkedList->head->next)
    {
        linkedList->last = linkedList->head;
        linkedList->head->previous = linkedList->head;
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
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }

    if (linkedList->head->next == linkedList->head)
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

    Node *ptr = linkedList->head->next;
    int counter = 0;
    while (ptr != linkedList->last)
    {
        if (counter == index)
        {
            break;
        }
        ptr = ptr->next;
        counter++;
    }

    if (counter != index)
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
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }

    Node *ptr = linkedList->head->next;
    size_t length = 0;
    while (ptr != linkedList->last)
    {
        length++;
        ptr = ptr->next;
    }
    length++;
    
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
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }

    if (linkedList->head->next == linkedList->head)
    {
        printf("The Linked List was empty!\n");
        return;
    }

    printf("head");
    printf(" -> header");
    Node *ptr = linkedList->head->next;
    while (ptr != linkedList->last)
    {
        printf(" <--> %d", ptr->value);
        ptr = ptr->next;
    }
    printf(" <--> %d <--> head", ptr->value);
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
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }

    if (linkedList->head->next == NULL)
    {
        printf("The Linked List was empty!\n");
        return;
    }

    int index = 0;
    Node *ptr = linkedList->head->next;
    printf("head:\n");
    printf("address: %d, ", linkedList->head);
    printf("value: NULL, ");
    printf("previous address: %d ", linkedList->head->previous);
    printf("next address: %d\n", linkedList->head->next);
    while (ptr != linkedList->last)
    {
        printf("%d. index:\n", index);
        printf("address: %d, ", ptr);
        printf("value: %d, ", ptr->value);
        printf("previous address: %d ", ptr->previous);
        printf("next address: %d\n", ptr->next);
        ptr = ptr->next;
        index++;
    }
    printf("%d. index:\n", index);
    printf("address: %d, ", ptr);
    printf("value: %d, ", ptr->value);
    printf("previous address: %d ", ptr->previous);
    printf("next address: %d\n", ptr->next);
}