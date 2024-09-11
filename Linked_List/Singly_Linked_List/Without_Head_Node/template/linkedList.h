#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    void *value;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    size_t length;
} LinkedList;

LinkedList *initLinkedList();

void deleteLinkedList(LinkedList *linkedList);

#define push(__linkedList, __value) ({ \
    int __ret = 0; \
    if (__linkedList == NULL) { \
        fprintf(stderr, "ERROR: Linked List is not initialized!\n"); \
    } \
    else { \
        Node *__newNode = malloc(sizeof(Node)); \
        if (__newNode == NULL) { \
            fprintf(stderr, "ERROR: Memory allocation for new Node failed!\n"); \
            deleteLinkedList(__linkedList); \
        } \
        else { \
            __newNode->value = __value; \
            __newNode->next = __linkedList->head; \
            __linkedList->head = __newNode; \
            __linkedList->length++; \
            __ret = 1; \
        } \
    } \
    __ret; \
})

#define pop(__linkedList) ({ \
    int __ret = 0; \
    if (__linkedList == NULL) { \
        fprintf(stderr, "ERROR: Linked List is not initialized!\n"); \
    } \
    else if (__linkedList->head == NULL) { \
        fprintf(stderr, "ERROR: No elements in the Linked List!\n"); \
    } \
    else { \
        Node *__ptr = __linkedList->head; \
        if (__ptr != NULL) { \
            __linkedList->head = __ptr->next; \
            free(__ptr); \
            __linkedList->length--; \
            __ret = 1; \
        } \
    } \
    __ret; \
})

#define popAt(__linkedList, __index) ({ \
    int __ret = 0; \
    if (__linkedList == NULL) { \
        fprintf(stderr, "ERROR: Linked List is not initialized!\n"); \
    } \
    else if (__linkedList->head == NULL) { \
        fprintf(stderr, "ERROR: No elements in the Linked List!\n"); \
    } \
    else if (__index < 0) { \
        fprintf(stderr, "ERROR: Index out of bound!\n"); \
    } \
    else { \
        Node *__ptr = __linkedList->head; \
        int __counter = 0; \
        while (__ptr != NULL) { \
            if (__counter == __index - 1) { \
                break; \
            } \
            __ptr = __ptr->next; \
            __counter++; \
        } \
        if (__ptr == NULL || __ptr->next == NULL) { \
            fprintf(stderr, "ERROR: Index out of bound!\n"); \
        } \
        else { \
            Node *__temp = __ptr->next; \
            __ptr->next = __temp->next; \
            free(__temp); \
            __linkedList->length--; \
            __ret = 1; \
        } \
    } \
    __ret; \
})

#define valueAt(__linkedList, __index, __type) ({ \
    __type __ret = (__type)NULL; \
    if (__linkedList == NULL) { \
        fprintf(stderr, "ERROR: Linked List is not initialized!\n"); \
    } \
    else if (__linkedList->head == NULL) { \
        fprintf(stderr, "ERROR: No elements in the Linked List!\n"); \
    } \
    else if (__index < 0) { \
        fprintf(stderr, "ERROR: Index out of bound!\n"); \
    } \
    else { \
        Node *__ptr = __linkedList->head; \
        int __counter = 0; \
        while (__ptr != NULL) { \
            if (__counter == __index) { \
                break; \
            } \
            __ptr = __ptr->next; \
            __counter++; \
        } \
        if (__ptr == NULL) { \
            fprintf(stderr, "ERROR: Index out of bound!\n"); \
        } \
        else { \
            __ret = __ptr->value; \
        } \
    } \
    __ret; \
})

size_t length(LinkedList *linkedList);

#endif