#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>

#define STACK_INCREMENT_SIZE 10

typedef struct Stack
{
    void *data;
    int currentSize;
    int maxHeight;
    size_t elementSize;
} Stack;

#define initStack(__type) ({ \
    Stack *__ret = (Stack *)NULL; \
    Stack* __stack = (Stack *)malloc(sizeof(Stack)); \
    if (__stack == NULL) { \
        fprintf(stderr, "ERROR: Memory allocation for Stack structure failed!\n"); \
    } \
    else { \
        __stack->data = malloc(STACK_INCREMENT_SIZE * sizeof(__type)); \
        if (__stack->data == NULL) { \
            fprintf(stderr, "ERROR: Memory allocation for Stack data failed!\n"); \
            free(__stack); \
        } \
        else { \
            __stack->currentSize = 0; \
            __stack->maxHeight = STACK_INCREMENT_SIZE; \
            __stack->elementSize = sizeof(__type); \
            __ret = __stack; \
        } \
    } \
    __ret; \
})

#define deleteStack(__stack) ({ \
    int __ret = 0; \
    if (__stack != NULL) { \
        if (__stack->data != NULL) { \
            free(__stack->data); \
        } \
        free(__stack); \
        __ret = 1; \
    } \
    __ret; \
})

#define push(__stack, __value) ({ \
    int __ret = 0; \
    if (__stack == NULL) { \
        fprintf(stderr, "ERROR: Stack is not initialized!\n"); \
    } \
    else if (__stack->elementSize != sizeof(__value)) { \
        fprintf(stderr, "ERROR: Type mismatch!\n"); \
    } \
    else { \
        if (isFull(__stack) > 0) { \
            int __size = STACK_INCREMENT_SIZE; \
            void *__temp = realloc(__stack->data, (__stack->maxHeight + __size) * __stack->elementSize); \
            if (__temp == NULL) { \
                fprintf(stderr, "ERROR: Memory reallocation failed!\n"); \
                deleteStack(__stack); \
            } \
            else { \
                __stack->data = __temp; \
                __stack->maxHeight += __size; \
                ((typeof(__value) *)__stack->data)[__stack->currentSize++] = __value; \
                __ret = 1; \
            } \
        } \
        else { \
            ((typeof(__value) *)__stack->data)[__stack->currentSize++] = __value; \
            __ret = 1; \
        } \
    } \
    __ret; \
})

#define pop(__stack, __type) ({ \
    __type __ret = (__type)NULL;; \
    if (__stack == NULL) { \
        fprintf(stderr, "ERROR: Stack is not initialized!\n"); \
    } \
    else if (__stack->elementSize != sizeof(__type)) { \
        fprintf(stderr, "ERROR: Type mismatch!\n"); \
    } \
    else { \
        if (isEmpty(__stack) == 0) { \
            __ret = ((__type *)__stack->data)[--__stack->currentSize]; \
        } \
    } \
    __ret; \
})

#define top(__stack, __type) ({ \
    __type __ret = (__type)NULL; \
    if (__stack == NULL) { \
        fprintf(stderr, "ERROR: Stack is not initialized!\n"); \
    } \
    else if (__stack->elementSize != sizeof(__type)) { \
        fprintf(stderr, "ERROR: Type mismatch!\n"); \
    } \
    else { \
        if (isEmpty(__stack) == 0) { \
            __ret = ((__type *)__stack->data)[__stack->currentSize - 1]; \
        } \
    } \
    __ret; \
})

#define isFull(__stack) ({ \
    int __ret = 0; \
    if (__stack == NULL) { \
        fprintf(stderr, "ERROR: Stack is not initialized!\n"); \
    } \
    else { \
        __ret = __stack->currentSize == __stack->maxHeight; \
    } \
    __ret; \
})

#define isEmpty(__stack) ({ \
    int __ret = 0; \
    if (__stack == NULL) { \
        fprintf(stderr, "ERROR: Stack is not initialized!\n"); \
    } \
    else { \
        __ret = __stack->currentSize == 0; \
    } \
    __ret; \
})

#define setEmpty(__stack) ({ \
    int __ret = 0; \
    if (__stack == NULL) { \
        fprintf(stderr, "ERROR: Stack is not initialized!\n"); \
    } \
    else { \
        __stack->currentSize = 0; \
        __ret = 1; \
    } \
    __ret; \
})

#define length(__stack) ({ \
    int __ret = 0; \
    if (__stack == NULL) { \
        fprintf(stderr, "ERROR: Stack is not initialized!\n"); \
    } \
    else { \
        __ret = __stack->currentSize; \
    } \
    __ret; \
})

#endif