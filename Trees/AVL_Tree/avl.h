#ifndef AVL_H
#define AVL_H
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int key;
    int balance;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *initAVL(int value);

void deleteAVL(struct TreeNode *root);

void _deleteNode(struct TreeNode *node);

struct TreeNode *_balancePP(struct TreeNode *node, int *rebalance);

struct TreeNode *_balanceMM(struct TreeNode *node, int *rebalance);

struct TreeNode *_balancePPp(struct TreeNode *node, struct TreeNode *right);

struct TreeNode *_balanceMMm(struct TreeNode *node, struct TreeNode *left);

struct TreeNode *_balancePPm(struct TreeNode *node, struct TreeNode *right);

struct TreeNode *_balanceMMp(struct TreeNode *node, struct TreeNode *left);

struct TreeNode *_balancePP0(struct TreeNode *node, struct TreeNode *right);

struct TreeNode *_balanceMM0(struct TreeNode *node, struct TreeNode *left);

struct TreeNode *insert(struct TreeNode *root, int value);

struct TreeNode *_insertRec(struct TreeNode *node, int value, struct TreeNode *toInsert, int *rebalance);

struct TreeNode *_leftSubTreeGrown(struct TreeNode *node, int *rebalance);

struct TreeNode *_rightSubTreeGrown(struct TreeNode *node, int *rebalance);

struct TreeNode *_leftSubTreeShrunk(struct TreeNode *node, int *rebalance);

struct TreeNode *_rightSubTreeShrunk(struct TreeNode *node, int *rebalance);

struct TreeNode *remMin(struct TreeNode *node, struct TreeNode **out);

struct TreeNode *_remMinRec(struct TreeNode *node, struct TreeNode **out, int *rebalance);

struct TreeNode *removeAVL(struct TreeNode *root, int value);

struct TreeNode *_removeRec(struct TreeNode *node, int value, int *rebalance);

struct TreeNode *_removeRoot(struct TreeNode *node, int *rebalance);

struct TreeNode *_rightSubTreeMinToRoot(struct TreeNode *node, int *rebalance);

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