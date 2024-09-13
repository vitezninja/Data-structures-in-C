#include "stack.h"
#include <stdio.h>

static char* strings[] = {
    "Hello",
    "World",
    "This",
    "Is",
    "A",
    "Test",
    "String",
    "Array",
    "For",
    "Stack",
    "Implementation",
    "In",
    "C"
};

int main()
{
    Stack *stack = initStack(sizeof(char *));

    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: Stack initialization failed!\n");
        return 1;
    }

    for (int i = 0; i < sizeof(strings) / sizeof(char *); i++)
    {
        push(stack, strings[i]);
    }

    for (size_t i = 0; i < length(stack); i++)
    {
        printf("%s, ", ((char **)stack->data)[i]);
    }
    printf("\n");
    
    for (size_t i = 0; i < 4; i++)
    {
        pop(stack, char*);
    }

    for (size_t i = 0; i < length(stack); i++)
    {
        printf("%s, ", ((char **)stack->data)[i]);
    }
    printf("\n");

    printf("Top: %s\n", top(stack, char*));

    deleteStack(stack);
    return 0;
}