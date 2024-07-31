#include "bst.h"

struct TreeNode *initBST(int value)
{
    struct TreeNode *root = malloc(1 * sizeof(struct TreeNode));
    if (root == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for Binary Search Tree structure failed!\n");
        exit(-1);
    }

    root->key = value;
    root->left = NULL;
    root->right = NULL;

    return root;
}

void deleteBST(struct TreeNode *root)
{
    if (root == NULL)
    {
        fprintf(stderr, "ERROR: Binary Search Tree is not initialized!\n");
        exit(-1);
    }

    _deleteNode(root);
}

void _deleteNode(struct TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    _deleteNode(node->left);
    _deleteNode(node->right);
    free(node);
}

struct TreeNode *insert(struct TreeNode *root, int value)
{
    struct TreeNode *newNode = malloc(1 * sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for new TreeNode failed!\n");
        deleteBST(root);
        exit(-1);
    }

    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return _insertRec(root, value, newNode);
}

struct TreeNode *_insertRec(struct TreeNode *node, int value, struct TreeNode *toInsert)
{
    if (node == NULL)
    {
        return toInsert;
    }
    
    if (node->key > value)
    {
        node->left = _insertRec(node->left, value, toInsert);
    }
    else if (node->key < value)
    {
        node->right = _insertRec(node->right, value, toInsert);
    }

    return node;
}

struct TreeNode *removeBST(struct TreeNode *root, int value)
{
    if (root == NULL)
    {
        fprintf(stderr, "ERROR: Binary Search Tree is not initialized!\n");
        exit(-1);
    }
    
    return _removeRec(root, value);
}

struct TreeNode *_removeRec(struct TreeNode *node, int value)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (node->key < value)
    {
        node->right = _removeRec(node->right, value);
    }
    else if (node->key > value)
    {
        node->left = _removeRec(node->left, value);
    }
    else
    {
        int _childCount = childCount(node);
        if (_childCount == 0)
        {
            free(node);
            return NULL;
        }
        else if (_childCount == 1)
        {
            struct TreeNode *temp;

            temp = node->left != NULL ? node->left : node->right;

            free(node);
            return temp;
        }
        else
        {
            struct TreeNode *temp = _findMin(node->right);
            node->key = temp->key;
            node->right = _removeRec(node->right, temp->key);
        }
    }

    return node;
}

struct TreeNode *_findMin(struct TreeNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    while (node->left != NULL)
    {
        node = node->left;
    }
    
    return node;
}

struct TreeNode *search(struct TreeNode *root, int target)
{
    if (root == NULL)
    {
        fprintf(stderr, "ERROR: Binary Search Tree is not initialized!\n");
        exit(-1);
    }

    if (root->key == target)
    {
        return root;
    }
    else if (root->key > target)
    {
        return root->left == NULL ? NULL : search(root->left, target);
    }
    else
    {
        return root->right == NULL ? NULL : search(root->right, target);
    }
}

int childCount(struct TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int count = 0;
    if (node->left != NULL)
    {
        count++;
    }
    if (node->right != NULL)
    {
        count++;
    }

    return count;
}

void preOrderPrint(struct TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("Pre-order: \n");
    _preOrderPrintRec(node);
    printf("\n");
}

void _preOrderPrintRec(struct TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%d ", node->key);
    _preOrderPrintRec(node->left);
    _preOrderPrintRec(node->right);
}

void postOrderPrint(struct TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("Post-order: \n");
    _postOrderPrintRec(node);
    printf("\n");
}

void _postOrderPrintRec(struct TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    _postOrderPrintRec(node->left);
    _postOrderPrintRec(node->right);
    printf("%d ", node->key);
}

void inOrderPrint(struct TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("In-order: \n");
    _inOrderPrintRec(node);
    printf("\n");
}

void _inOrderPrintRec(struct TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    _inOrderPrintRec(node->left);
    printf("%d ", node->key);
    _inOrderPrintRec(node->right);
}
