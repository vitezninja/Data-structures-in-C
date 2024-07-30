#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *initBST(int value);

void deleteBST(struct TreeNode *root);

void _deleteNode(struct TreeNode *node);

void insert(struct TreeNode *root, int value);

struct TreeNode * _insertRec(struct TreeNode *node, int value, struct TreeNode *toInsert);

void removeBST(struct TreeNode *root, int value);

struct TreeNode *_removeRec(struct TreeNode *node, int value);

struct TreeNode *_findMin(struct TreeNode *node);

struct TreeNode *search(struct TreeNode *root, int target);

int childCount(struct TreeNode *node);

void preOrderPrint(struct TreeNode *node);

void _preOrderPrintRec(struct TreeNode *node);

void postOrderPrint(struct TreeNode *node);

void _postOrderPrintRec(struct TreeNode *node);

void inOrderPrint(struct TreeNode *node);

void _inOrderPrintRec(struct TreeNode *node);

#endif