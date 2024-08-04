#include "stack.h"

Stack *initStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for Stack structure failed!\n");
        exit(-1);
    }

    int size = STACK_INCREMENT_SIZE;

    stack->data = (int *)malloc(size * sizeof(int));
    if (stack->data == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for Stack data failed!\n");
        free(stack);
        exit(-1);
    }

    stack->currentSize = 0;
    stack->maxHeight = size;
    return stack;
}

void deleteStack(Stack *stack)
{
    if (stack == NULL)
    {
        return;
    }

    if (stack->data == NULL)
    {
        free(stack);
        return;
    }

    free(stack->data);
    free(stack);
}

void push(Stack *stack, int value)
{
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: Stack is not initialized!\n");
        exit(-1);
    }

    if (isFull(stack))
    {
        int size = STACK_INCREMENT_SIZE;
        int *temp = (int *)realloc(stack->data, (stack->maxHeight + size) * sizeof(int));
        if (temp == NULL)
        {
            fprintf(stderr, "ERROR: Memory reallocation failed!\n");
            deleteStack(stack);
            exit(-1);
        }
        stack->data = temp;
        stack->maxHeight += size;
    }

    stack->data[stack->currentSize++] = value;
}

int pop(Stack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: Stack is not initialized!\n");
        exit(-1);
    }

    if (isEmpty(stack))
    {
        deleteStack(stack);
        fprintf(stderr, "ERROR: The Stack was empty!\n");
        exit(-1);
    }

    return stack->data[--stack->currentSize];
}

int top(Stack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: Stack is not initialized!\n");
        exit(-1);
    }

    if (isEmpty(stack))
    {
        deleteStack(stack);
        fprintf(stderr, "ERROR: The Stack was empty!\n");
        exit(-1);
    }

    return stack->data[stack->currentSize - 1];
}

int isFull(Stack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: Stack is not initialized!\n");
        exit(-1);
    }

    return stack->currentSize == stack->maxHeight;
}

int isEmpty(Stack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: Stack is not initialized!\n");
        exit(-1);
    }

    return stack->currentSize == 0;
}

void setEmpty(Stack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: Stack is not initialized!\n");
        exit(-1);
    }

    stack->currentSize = 0;
}

size_t length(Stack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: Stack is not initialized!\n");
        exit(-1);
    }

    return stack->currentSize;
}

void printStack(Stack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: Stack is not initialized!\n");
        exit(-1);
    }

    if (isEmpty(stack))
    {
        printf("The Stack was empty!\n");
        return;
    }

    for (size_t i = 0; i < stack->currentSize; i++)
    {
        printf("At %ld: %d\n", i, stack->data[i]);
    }
}