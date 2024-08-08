#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *previous;
    struct Node *next;
} Node;

Node *initLinkedList(int value);

void deleteLinkedList(Node *head);

Node *insert(Node *head, int value);

Node *removeLL(Node *head);

int valueAt(Node *head, int offset);

size_t length(Node *head);

void printLinkedList(Node *head);

#endif