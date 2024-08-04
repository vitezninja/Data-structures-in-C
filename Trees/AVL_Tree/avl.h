#ifndef AVL_H
#define AVL_H
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int key;
    int balance;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *initAVL(int value);

void deleteAVL(TreeNode *root);

void _deleteNode(TreeNode *node);

TreeNode *_balancePP(TreeNode *node, int *rebalance);

TreeNode *_balanceMM(TreeNode *node, int *rebalance);

TreeNode *_balancePPp(TreeNode *node, TreeNode *right);

TreeNode *_balanceMMm(TreeNode *node, TreeNode *left);

TreeNode *_balancePPm(TreeNode *node, TreeNode *right);

TreeNode *_balanceMMp(TreeNode *node, TreeNode *left);

TreeNode *_balancePP0(TreeNode *node, TreeNode *right);

TreeNode *_balanceMM0(TreeNode *node, TreeNode *left);

TreeNode *insert(TreeNode *root, int value);

TreeNode *_insertRec(TreeNode *node, int value, TreeNode *toInsert, int *rebalance);

TreeNode *_leftSubTreeGrown(TreeNode *node, int *rebalance);

TreeNode *_rightSubTreeGrown(TreeNode *node, int *rebalance);

TreeNode *_leftSubTreeShrunk(TreeNode *node, int *rebalance);

TreeNode *_rightSubTreeShrunk(TreeNode *node, int *rebalance);

TreeNode *remMin(TreeNode *node, TreeNode **out);

TreeNode *_remMinRec(TreeNode *node, TreeNode **out, int *rebalance);

TreeNode *removeAVL(TreeNode *root, int value);

TreeNode *_removeRec(TreeNode *node, int value, int *rebalance);

TreeNode *_removeRoot(TreeNode *node, int *rebalance);

TreeNode *_rightSubTreeMinToRoot(TreeNode *node, int *rebalance);

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