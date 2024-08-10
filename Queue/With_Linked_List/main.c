#include "queue.h"
#include <stdio.h>

void main()
{
    Queue *queue = initQueue();
    enqueue(queue, 1);
    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 100);
    enqueue(queue, 40);
    print(queue);
    debug(queue);
    printf("Length: %ld\n", length(queue));
    printf("Peek: %d\n", peek(queue));
    
    dequeue(queue);
    print(queue);
    dequeue(queue);
    print(queue);
    dequeue(queue);
    print(queue);
    debug(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    print(queue);
    printf("Peek: %d\n", peek(queue));

    deleteQueue(queue);
}