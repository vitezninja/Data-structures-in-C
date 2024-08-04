#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

struct TreeNode *initBST(int value);

void deleteBST(TreeNode *root);

void _deleteNode(TreeNode *node);

TreeNode *insert(TreeNode *root, int value);

TreeNode *_insertRec(TreeNode *node, int value, TreeNode *toInsert);

TreeNode *removeBST(TreeNode *root, int value);

TreeNode *_removeRec(TreeNode *node, int value);

TreeNode *_findMin(TreeNode *node);

TreeNode *search(TreeNode *root, int target);

int childCount(TreeNode *node);

void preOrderPrint(TreeNode *node);

void _preOrderPrintRec(TreeNode *node);

void postOrderPrint(TreeNode *node);

void _postOrderPrintRec(TreeNode *node);

void inOrderPrint(TreeNode *node);

void _inOrderPrintRec(TreeNode *node);

#endif