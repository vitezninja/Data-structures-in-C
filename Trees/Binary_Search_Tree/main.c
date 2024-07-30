#include "bst.h"
#include <stdio.h>

void main()
{
    struct TreeNode *root = initBST(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    if (search(root, 60) != NULL) {
        printf("60 found\n");
    }
    else {
        printf("60 not found\n");
    }

    preOrderPrint(root);
    postOrderPrint(root);
    inOrderPrint(root);

    removeBST(root, 70);
    printf("After Delete:\n");
    preOrderPrint(root);

    deleteBST(root);
}