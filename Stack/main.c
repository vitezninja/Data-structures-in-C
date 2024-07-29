#include "stack.h"
#include <stdio.h>

void main()
{
    struct Stack *stack = initStack();
    printf("isEmpty: %d\n", isEmpty(stack));
    printf("isFull: %d\n", isFull(stack));

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    push(stack, 7);
    push(stack, 8);
    push(stack, 9);
    push(stack, 10);
    push(stack, 11);
    printStack(stack);
    printf("Length: %ld\n", length(stack));
    setEmpty(stack);
    push(stack, 12);
    push(stack, 13);
    push(stack, 14);
    push(stack, 15);
    printStack(stack);
    printf("Length: %ld\n", length(stack));
    printf("Value at top: %d\n", top(stack));
    
    int value = pop(stack);
    printf("Removed: %d\n", value);
    printStack(stack);
    value = pop(stack);
    printf("Removed: %d\n", value);
    printStack(stack);
    value = pop(stack);
    printf("Removed: %d\n", value);
    printStack(stack);
    value = pop(stack);
    printf("Removed: %d\n", value);
    printStack(stack);

    deleteStack(stack);
}