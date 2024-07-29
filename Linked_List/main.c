#include "linkedList.h"
#include <stdio.h>

void main()
{
    initLinkedList();

    insertFirst(1);
    insertAfter(5, 0);
    insertAfter(10, 1);
    insertAfter(20, 2);
    insertFirst(30);
    insertLast(100);
    insertAfter(40, 3);
    printLinkedList();
    printf("Length: %ld\n", length());
    int index = 5;
    printf("Value at %d: %d\n", index, valueAt(index));
    
    int value = removeFirst();
    printf("Removed: %d\n", value);
    printLinkedList();
    value = removeLast();
    printf("Removed: %d\n", value);
    printLinkedList();
    value = removeAfter(2);
    printf("Removed: %d\n", value);
    printLinkedList();

    deleteLinkedList();
}