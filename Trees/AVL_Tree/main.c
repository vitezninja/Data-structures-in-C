#include "avl.h"
#include <stdio.h>

void main()
{
    struct TreeNode *root = initAVL(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    preOrderPrint(root);
    postOrderPrint(root);
    inOrderPrint(root);

    if (search(root, 60) != NULL) {
        printf("60 found\n");
    }
    else {
        printf("60 not found\n");
    }

    struct TreeNode *out;
    root = removeAVL(root, 70);
    printf("After Delete: \n");
    preOrderPrint(root);

    deleteAVL(root);
}