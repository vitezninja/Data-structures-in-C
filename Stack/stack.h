#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>

#define STACK_INCREMENT_SIZE 10;

struct Stack
{
    int *data;
    int currentSize;
    int maxHeight;
};

struct Stack *initStack();

void deleteStack(struct Stack *stack);

void push(struct Stack *stack, int value);

int pop(struct Stack *stack);

int top(struct Stack *stack);

int isFull(struct Stack *stack);

int isEmpty(struct Stack *stack);

void setEmpty(struct Stack *stack);

size_t length(struct Stack *stack);

void printStack(struct Stack *stack);

#endif