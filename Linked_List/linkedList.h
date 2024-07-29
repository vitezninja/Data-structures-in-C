#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node *initLinkedList();

void deleteLinkedList(struct Node *head);

void insertFirst(struct Node *head, int value);

void insertAfter(struct Node *head, int value, int offset);

void insertLast(struct Node *head, int value);

int removeFirst(struct Node *head);

int removeAfter(struct Node *head, int offset);

int removeLast(struct Node *head);

int valueAt(struct Node *head, int offset);

size_t length(struct Node *head);

void printLinkedList(struct Node *head);

#endif