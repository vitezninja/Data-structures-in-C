#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *initLinkedList();

void deleteLinkedList(Node *head);

void insertFirst(Node *head, int value);

void insertAfter(Node *head, int value, int offset);

void insertLast(Node *head, int value);

int removeFirst(Node *head);

int removeAfter(Node *head, int offset);

int removeLast(Node *head);

int valueAt(Node *head, int offset);

size_t length(Node *head);

void printLinkedList(Node *head);

#endif