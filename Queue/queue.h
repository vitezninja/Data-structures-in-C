#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_INCREMENT_SIZE 10;

struct Queue
{
    int *data;
    int start;
    int size;
    int maxLength;
};

struct Queue *initQueue();

void deleteQueue(struct Queue *queue);

void enqueue(struct Queue *queue, int value);

int dequeue(struct Queue *queue);

int peek(struct Queue *queue);

int isFull(struct Queue *queue);

int isEmpty(struct Queue *queue);

void setEmpty(struct Queue *queue);

size_t length(struct Queue *queue);

void printQueue(struct Queue *queue);

#endif