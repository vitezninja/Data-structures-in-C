#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_INCREMENT_SIZE 10;

typedef struct Queue
{
    int *data;
    int start;
    int size;
    int maxLength;
} Queue;

Queue *initQueue();

void deleteQueue(Queue *queue);

void enqueue(Queue *queue, int value);

int dequeue(Queue *queue);

int peek(Queue *queue);

int isFull(Queue *queue);

int isEmpty(Queue *queue);

void setEmpty(Queue *queue);

size_t length(Queue *queue);

void print(Queue *queue);

#endif