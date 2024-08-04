#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>

#define STACK_INCREMENT_SIZE 10;

typedef struct Stack
{
    int *data;
    int currentSize;
    int maxHeight;
} Stack;

Stack *initStack();

void deleteStack(Stack *stack);

void push(Stack *stack, int value);

int pop(Stack *stack);

int top(Stack *stack);

int isFull(Stack *stack);

int isEmpty(Stack *stack);

void setEmpty(Stack *stack);

size_t length(Stack *stack);

void printStack(Stack *stack);

#endif