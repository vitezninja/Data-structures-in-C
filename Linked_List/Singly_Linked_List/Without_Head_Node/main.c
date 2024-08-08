#include "linkedList.h"
#include <stdio.h>

void main()
{
    struct Node *linkedList = initLinkedList(1);

    linkedList = insert(linkedList, 5);
    linkedList = insert(linkedList, 10);
    linkedList = insert(linkedList, 20);
    linkedList = insert(linkedList, 30);
    linkedList = insert(linkedList, 100);
    linkedList = insert(linkedList, 40);
    printLinkedList(linkedList);
    printf("Length: %ld\n", length(linkedList));
    int index = 5;
    printf("Value at %d. index: %d\n", index, valueAt(linkedList, index));
    
    linkedList = removeLL(linkedList);
    printLinkedList(linkedList);
    linkedList = removeLL(linkedList);
    printLinkedList(linkedList);
    linkedList = removeLL(linkedList);
    printLinkedList(linkedList);

    deleteLinkedList(linkedList);
}