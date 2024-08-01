#include "avl.h"

struct TreeNode *initAVL(int value)
{
    struct TreeNode *root = malloc(1 * sizeof(struct TreeNode));
    if (root == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for AVL Tree structure failed!\n");
        exit(-1);
    }

    root->key = value;
    root->balance = 0;
    root->left = NULL;
    root->right = NULL;

    return root;
}

void deleteAVL(struct TreeNode *root)
{
    if (root == NULL)
    {
        fprintf(stderr, "ERROR: AVL Tree is not initialized!\n");
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

struct TreeNode *_balancePP(struct TreeNode *node, int *rebalance)
{
    struct TreeNode *right = node->right;
    if (right->balance == -1)
    {
        node = _balancePPm(node, right);
    }
    else if (right->balance == 0)
    {
        node = _balancePP0(node, right);
        *rebalance = 0;
    }
    else if (right->balance == 1)
    {
        node = _balancePPp(node, right);
    }

    return node;
}

struct TreeNode *_balanceMM(struct TreeNode *node, int *rebalance)
{
    struct TreeNode *left = node->left;
    if (left->balance == -1)
    {
        node = _balanceMMm(node, left);
    }
    else if (left->balance == 0)
    {
        node = _balanceMM0(node, left);
        *rebalance = 0;
    }
    else if (left->balance == 1)
    {
        node = _balanceMMp(node, left);
    }

    return node;
}

struct TreeNode *_balancePPp(struct TreeNode *node, struct TreeNode *right)
{
    node->right = right->left;
    right->left = node;
    right->balance = 0;
    node->balance = 0;
    return right;
}

struct TreeNode *_balanceMMm(struct TreeNode *node, struct TreeNode *left)
{
    node->left = left->right;
    left->right = node;
    left->balance = 0;
    node->balance = 0;
    return left;
}

struct TreeNode *_balancePPm(struct TreeNode *node, struct TreeNode *right)
{
    struct TreeNode *left = right->left;
    node->right = left->left;
    right->left = left->right;
    left->left = node;
    left->right = right;
    node->balance = -1 * (left->balance + 1) / 2;
    right->balance = (1 - left->balance) / 2;
    left->balance = 0;
    return left;
}

struct TreeNode *_balanceMMp(struct TreeNode *node, struct TreeNode *left)
{
    struct TreeNode *right = left->right;
    left->right = right->left;
    node->left = right->right;
    right->left = left;
    right->right = node;
    left->balance = -1 * (right->balance + 1) / 2;
    node->balance = (1 - right->balance) / 2;
    right->balance = 0;
    return right;
}

struct TreeNode *_balancePP0(struct TreeNode *node, struct TreeNode *right)
{
    node->right = right->left;
    right->left = node;
    node->balance = 1;
    right->balance = -1;
    return right;
}

struct TreeNode *_balanceMM0(struct TreeNode *node, struct TreeNode *left)
{
    node->left = left->right;
    left->right = node;
    node->balance = -1;
    left->balance = 1;
    return left;
}

struct TreeNode *insert(struct TreeNode *root, int value)
{
    struct TreeNode *newNode = malloc(1 * sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation for new TreeNode failed!\n");
        deleteAVL(root);
        exit(-1);
    }

    newNode->key = value;
    newNode->balance = 0;
    newNode->left = NULL;
    newNode->right = NULL;

    int rebalance = 0;
    return _insertRec(root, value, newNode, &rebalance);
}

struct TreeNode *_insertRec(struct TreeNode *node, int value, struct TreeNode *toInsert, int *rebalance)
{
    if (node == NULL)
    {
        *rebalance = 1;
        return toInsert;
    }
    
    if (node->key > value)
    {
        node->left = _insertRec(node->left, value, toInsert, rebalance);
        if (*rebalance)
        {
            node = _leftSubTreeGrown(node, rebalance);
        }
    }
    else if (node->key < value)
    {
        node->right = _insertRec(node->right, value, toInsert, rebalance);
        if (*rebalance)
        {
            node = _rightSubTreeGrown(node, rebalance);
        }
    }
    else
    {
        *rebalance = 0;
    }

    return node;
}

struct TreeNode *_leftSubTreeGrown(struct TreeNode *node, int *rebalance)
{
    if (node->balance == -1)
    {
        struct TreeNode *left = node->left;
        node = left->balance == -1 ? _balanceMMm(node, left) : _balanceMMp(node, left);
        *rebalance = 0;
    }
    else
    {
        node->balance = node->balance - 1;
        *rebalance = node->balance < 0;
    }

    return node;
}

struct TreeNode *_rightSubTreeGrown(struct TreeNode *node, int *rebalance)
{
    if (node->balance == 1)
    {
        struct TreeNode *right = node->right;
        node = right->balance == 1 ? _balancePPp(node, right) : _balancePPm(node, right);
        *rebalance = 0;
    }
    else
    {
        node->balance = node->balance + 1;
        *rebalance = node->balance > 0;
    }

    return node;
}

struct TreeNode *_leftSubTreeShrunk(struct TreeNode *node, int *rebalance)
{
    if (node->balance == 1)
    {
        node = _balancePP(node, rebalance);
    }
    else
    {
        node->balance = node->balance + 1;
        *rebalance = node->balance == 0;
    }

    return node;
}

struct TreeNode *_rightSubTreeShrunk(struct TreeNode *node, int *rebalance)
{
    if (node->balance == -1)
    {
        node = _balanceMM(node, rebalance);
    }
    else
    {
        node->balance = node->balance - 1;
        *rebalance = node->balance == 0;
    }

    return node;
}

struct TreeNode *remMin(struct TreeNode *root, struct TreeNode **out)
{
    if (root == NULL)
    {
        fprintf(stderr, "ERROR: AVL Tree is not initialized!\n");
        exit(-1);
    }

    int rebalance = 0;
    return _remMinRec(root, out, &rebalance);
}

struct TreeNode *_remMinRec(struct TreeNode *node, struct TreeNode **out, int *rebalance)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (node->left == NULL)
    {
        *out = node;
        node = (*out)->right;
        (*out)->right = NULL;
        *rebalance = 1;
    }
    else
    {
        node->left = _remMinRec(node->left, out, rebalance);
        if (*rebalance)
        {
            node = _leftSubTreeShrunk(node, rebalance);
        }
    }
    return node;
}

struct TreeNode *removeAVL(struct TreeNode *root, int value)
{
    if (root == NULL)
    {
        fprintf(stderr, "ERROR: Binary Search Tree is not initialized!\n");
        exit(-1);
    }
    
    int rebalance = 0;
    return _removeRec(root, value, &rebalance);
}

struct TreeNode *_removeRec(struct TreeNode *node, int value, int *rebalance)
{
    if (node == NULL)
    {
        *rebalance = 0;
        return node;
    }
    
    if (node->key < value)
    {
        node->right = _removeRec(node->right, value, rebalance);
        if (*rebalance)
        {
            node = _rightSubTreeShrunk(node, rebalance);
        }
    }
    else if (node->key > value)
    {
        node->left = _removeRec(node->left, value, rebalance);
        if (*rebalance)
        {
            node = _leftSubTreeShrunk(node, rebalance);
        }
    }
    else
    {
        node = _removeRoot(node, rebalance);
    }

    return node;
}

struct TreeNode *_removeRoot(struct TreeNode *node, int *rebalance)
{
    struct TreeNode *pointer = node;
    if (node->left == NULL)
    {
        node = pointer->right;
        free(pointer);
        *rebalance = 1;
    }
    else if (node->right == NULL)
    {
        node = pointer->left;
        free(pointer);
        *rebalance = 1;
    }
    else if (node->left != NULL && node->right != NULL)
    {
        node = _rightSubTreeMinToRoot(node, rebalance);
        if (*rebalance)
        {
            node = _rightSubTreeShrunk(node, rebalance);
        }
    }

    return node;
}

struct TreeNode *_rightSubTreeMinToRoot(struct TreeNode *node, int *rebalance)
{
    struct TreeNode *out;
    node->right = _remMinRec(node->right, &out, rebalance);
    out->left = node->left;
    out->right = node->right;
    out->balance = node->balance;
    free(node);

    return out;
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
