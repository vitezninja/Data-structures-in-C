#include "queue.h"

Queue *initQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for Queue structure failed!\n");
        exit(-1);
    }

    queue->head = NULL;
    queue->last = NULL;

    return queue;
}

void deleteQueue(Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Queue is not initialized!\n");
        exit(-1);
    }

    Node *ptr = queue->head;
    Node *nextPtr;
    while(ptr != queue->last)
    {
        nextPtr = ptr->next;
        free(ptr);
        ptr = nextPtr;
    }
    free(ptr);
    free(queue);
}

void enqueue(Queue *queue, int value)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Queue is not initialized!\n");
        exit(-1);
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for new Queue data failed!\n");
        deleteQueue(queue);
        exit(-1);
    }

    newNode->value = value;
    //If the Queue is empty head is NULL
    if (queue->head == NULL)
    {
        newNode->previous = newNode;
        newNode->next = newNode;
        queue->head = newNode;
        queue->last = newNode;
        return;
    }

    newNode->previous = queue->last;
    newNode->next = queue->head;
    queue->head->previous = newNode;
    queue->head = newNode;
    queue->last->next = queue->head;
}

int dequeue(Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Queue is not initialized!\n");
        exit(-1);
    }

    if (queue->head == NULL)
    {
        printf("No elements in the Queue List!\n");
        return 0;
    }
    
    Node *ptr = queue->last;
    queue->last = queue->last->previous;
    queue->last->next = queue->head;
    queue->head->previous = queue->last;

    int value = ptr->value;
    free(ptr);
    return value;
}

int peek(Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Queue is not initialized!\n");
        exit(-1);
    }

    if (queue->head == NULL)
    {
        fprintf(stderr, "ERROR: No elements in the Queue!\n");
        deleteQueue(queue);
        exit(-1);
    }

    return queue->head->value;
}

size_t length(Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Queue is not initialized!\n");
        exit(-1);
    }

    Node *ptr = queue->head;
    size_t length = 0;
    while (ptr != queue->last)
    {
        length++;
        ptr = ptr->next;
    }
    length++;
    
    return length;
}

void print(Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    if (queue->head == NULL)
    {
        printf("The Linked List was empty!\n");
        return;
    }

    printf("tail -> ");
    Node *ptr = queue->head;
    while (ptr != queue->last)
    {
        printf("%d, ", ptr->value);
        ptr = ptr->next;
    }
    printf("%d <- head", ptr->value);
    printf("\n");
}

void debug(Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Linked List is not initialized!\n");
        exit(-1);
    }

    if (queue->head == NULL)
    {
        printf("The Linked List was empty!\n");
        return;
    }

    int index = 0;
    Node *ptr = queue->head;
    while (ptr != queue->last)
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