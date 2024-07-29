#include "linkedList.h"
#include <stdio.h>

void main()
{
    struct Node *linkedList = initLinkedList();

    insertFirst(linkedList, 1);
    insertAfter(linkedList, 5, 0);
    insertAfter(linkedList, 10, 1);
    insertAfter(linkedList, 20, 2);
    insertFirst(linkedList, 30);
    insertLast(linkedList, 100);
    insertAfter(linkedList, 40, 3);
    printLinkedList(linkedList);
    printf("Length: %ld\n", length(linkedList));
    int index = 5;
    printf("Value at %d: %d\n", index, valueAt(linkedList, index));
    
    int value = removeFirst(linkedList);
    printf("Removed: %d\n", value);
    printLinkedList(linkedList);
    value = removeLast(linkedList);
    printf("Removed: %d\n", value);
    printLinkedList(linkedList);
    value = removeAfter(linkedList, 2);
    printf("Removed: %d\n", value);
    printLinkedList(linkedList);

    deleteLinkedList(linkedList);
}