#include "queue.h"
#include <stdio.h>

void main()
{
    struct Queue *queue = initQueue();
    printf("isEmpty: %d\n", isEmpty(queue));
    printf("isFull: %d\n", isFull(queue));

    enqueue(queue, 1); 
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 10);
    printQueue(queue);
    printf("Length: %ld\n", length(queue));
    printf("isEmpty: %d\n", isEmpty(queue));
    printf("isFull: %d\n", isFull(queue));
    setEmpty(queue);
    enqueue(queue, 12);
    enqueue(queue, 13);
    enqueue(queue, 14);
    enqueue(queue, 15);
    printQueue(queue);
    printf("Length: %ld\n", length(queue));
    printf("Next value: %d\n", peek(queue));
    
    int value = dequeue(queue);
    printf("Removed: %d\n", value);
    printQueue(queue);
    value = dequeue(queue);
    printf("Removed: %d\n", value);
    printQueue(queue);
    value = dequeue(queue);
    printf("Removed: %d\n", value);
    printQueue(queue);
    value = dequeue(queue);
    printf("Removed: %d\n", value);
    printQueue(queue);

    deleteQueue(queue);
}