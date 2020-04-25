// 法一：递归实现
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#if 0
void inorder(struct TreeNode* root, int* returnSize, int *a) /* 中序 */
{
    if(!root) return;

    inorder(root->left, returnSize, a);

    a[ (*returnSize)++ ] = root->val;

    inorder(root->right, returnSize, a);

}

int size(struct TreeNode* root) /* 统计二叉树节点个数 */
{
    if(!root) return 0;
    return size(root->left) + size(root->right) + 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int treesize = size(root);
    int *a = (int*) malloc( treesize * sizeof(int) );
    memset(a, 0, treesize * sizeof(int));
    *returnSize = 0;
    inorder(root, returnSize, a);
    return a;
}
#endif

// 法二：栈实现
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    struct TreeNode **a = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    int *b = (int*)malloc(sizeof(int) * 10000);
    int i = 0, top = 0;
    struct TreeNode *p = NULL;
    a[0] = root; /* 根指针进栈 */
    
    while (top != -1) {
        while (a[top] != NULL) a[++top] = a[top]->left; /* 向左走到尽头 */
        top--; /* 退出空指针 */
        if(top != -1) {
            p = a[top];
            b[i++] = p->val;
            a[top] = p->right;
        }
    }
    
    *returnSize = i;
    return b;
}