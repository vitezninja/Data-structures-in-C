#include "linkedList.h"
#include <stdio.h>

void main()
{
    LinkedList *linkedList = initLinkedList();

    insert(linkedList, 1);
    insert(linkedList, 5);
    insert(linkedList, 10);
    insert(linkedList, 20);
    insert(linkedList, 30);
    insert(linkedList, 100);
    insert(linkedList, 40);
    printLinkedList(linkedList);
    printf("Length: %ld\n", length(linkedList));
    int index = 5;
    printf("Value at %d. index: %d\n", index, valueAt(linkedList, index));
    
    removeLL(linkedList);
    printLinkedList(linkedList);
    removeLL(linkedList);
    printLinkedList(linkedList);
    removeLL(linkedList);
    printLinkedList(linkedList);
    removeLL(linkedList);
    removeLL(linkedList);
    removeLL(linkedList);
    printLinkedList(linkedList);
    index = 0;
    printf("Value at %d. index: %d\n", index, valueAt(linkedList, index));

    deleteLinkedList(linkedList);
}