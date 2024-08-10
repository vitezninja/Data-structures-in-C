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

    //If the Linked List is empty head->next is NULL
    if (linkedList->head->next != NULL)
    {
        linkedList->head->next->previous = newNode;
    }
    linkedList->head->next = newNode;
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

    if (linkedList->head == linkedList->head->next)
    {
        fprintf(stderr, "ERROR: No elements in the Linked List!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }
    
    Node *ptr = linkedList->head->next;
    linkedList->head->next = linkedList->head->next->next;
    //If the Linked List only had 1 element (exluding head element) then after removal head->next is NULL
    if (linkedList->head->next != NULL)
    {
        linkedList->head->next->previous = linkedList->head;
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

    if (linkedList->head == linkedList->head->next)
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

    if (linkedList->head == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }
    
    Node *ptr = linkedList->head->next;
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
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }

    if (linkedList->head == linkedList->head->next)
    {
        printf("The Linked List was empty!\n");
        return;
    }

    printf("head");
    printf(" -> header");
    Node *ptr = linkedList->head->next;
    while (ptr != NULL)
    {
        printf(" <--> %d", ptr->value);
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
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        deleteLinkedList(linkedList);
        exit(-1);
    }

    if (linkedList->head == linkedList->head->next)
    {
        printf("The Linked List was empty!\n");
        return;
    }

    int index = 0;
    Node *ptr = linkedList->head->next;
    printf("head:\n");
    printf("address: %d, ", linkedList->head);
    printf("value: NULL, ");
    printf("previous address: NULL ");
    printf("next address: %d\n", linkedList->head->next);
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