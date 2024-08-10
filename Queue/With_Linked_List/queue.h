#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *previous;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *head;
    Node *last;
} Queue;

Queue *initQueue();

void deleteQueue(Queue *queue);

void enqueue(Queue *queue, int value);

int dequeue(Queue *queue);

int peek(Queue *queue);

size_t length(Queue *queue);

void print(Queue *queue);

void debug(Queue *queue);

#endif