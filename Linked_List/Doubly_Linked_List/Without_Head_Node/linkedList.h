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

typedef struct LinkedList
{
    Node *head;
} LinkedList;

LinkedList *initLinkedList(int value);

void deleteLinkedList(LinkedList *linkedList);

void insert(LinkedList *linkedList, int value);

void removeLL(LinkedList *linkedList);

int valueAt(LinkedList *linkedList, int offset);

size_t length(LinkedList *linkedList);

void printLinkedList(LinkedList *linkedList);

#endif