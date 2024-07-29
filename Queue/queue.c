#include "queue.h"

struct Queue *initQueue()
{
    struct Queue *queue = malloc(1 * sizeof(struct Queue));
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for Queue structure failed!\n");
        exit(-1);
    }

    int size = QUEUE_INCREMENT_SIZE;
    queue->data = malloc(size * sizeof(int));
    if (queue->data == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for Queue data failed!\n");
        free(queue);
        exit(-1);
    }

    queue->start = 0;
    queue->size = 0;
    queue->maxLength = size;
    return queue;
}

void deleteQueue(struct Queue *queue)
{
    if (queue == NULL)
    {
        return;
    }

    if (queue->data != NULL)
    {
        free(queue->data);
    }

    free(queue);
}

void enqueue(struct Queue *queue, int value)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Queue is not initialized!\n");
        exit(-1);
    }

    if (isFull(queue))
    {
        int size = QUEUE_INCREMENT_SIZE;
        int *temp = malloc((queue->maxLength + size) * sizeof(int));
        if (temp == NULL)
        {
            fprintf(stderr, "ERROR: Memory allocation failed!\n");
            deleteQueue(queue);
            exit(-1);
        }

        int currentPos = queue->start;
        for (size_t i = 0; i < queue->size; i++)
        {
            if (currentPos == queue->maxLength)
            {
                currentPos = 0;
            }
            temp[i] = queue->data[currentPos];
            currentPos++;
        }
        
        free(queue->data);
        queue->data = temp;
        queue->maxLength += size;
    }
    
    int tail = (queue->start + queue->size) % queue->maxLength;
    queue->data[tail] = value;
    queue->size++;
}

int dequeue(struct Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Queue is not initialized!\n");
        exit(-1);
    }

    if (isEmpty(queue))
    {
        deleteQueue(queue);
        fprintf(stderr, "ERROR: The Queue was empty!\n");
        exit(-1);
    }

    int value = queue->data[queue->start];
    queue->start = (queue->start + 1) % queue->maxLength;
    queue->size--;

    return value;
}

int peek(struct Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Queue is not initialized!\n");
        exit(-1);
    }

    if (isEmpty(queue))
    {
        deleteQueue(queue);
        fprintf(stderr, "ERROR: The Queue was empty!\n");
        exit(-1);
    }

    return queue->data[queue->start];
}

int isFull(struct Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Queue is not initialized!\n");
        exit(-1);
    }

    return queue->size == queue->maxLength;
}

int isEmpty(struct Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Queue is not initialized!\n");
        exit(-1);
    }

    return queue->size == 0;
}

void setEmpty(struct Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Queue is not initialized!\n");
        exit(-1);
    }

    queue->start = 0;
    queue->size = 0;
}

size_t length(struct Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Queue is not initialized!\n");
        exit(-1);
    }

    return queue->size;
}

void printQueue(struct Queue *queue)
{
    if (queue == NULL)
    {
        fprintf(stderr, "ERROR: Queue is not initialized!\n");
        exit(-1);
    }

    if (isEmpty(queue))
    {
        printf("The Queue was empty!\n");
        return;
    }

    int i = queue->start;
    size_t counter = 0;
    while (counter < queue->size)
    {
        printf("At %ld: %d\n", counter, queue->data[i]);
        i = (i + 1) % queue->maxLength;
        counter++;
    }
}