#include "bst.h"
#include <stdio.h>

void main()
{
    struct TreeNode *root = initBST(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    if (search(root, 60) != NULL) {
        printf("60 found\n");
    }
    else {
        printf("60 not found\n");
    }

    preOrderPrint(root);
    postOrderPrint(root);
    inOrderPrint(root);

    root = removeBST(root, 70);
    printf("After Delete:\n");
    preOrderPrint(root);

    deleteBST(root);
}