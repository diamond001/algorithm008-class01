struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    if ( NULL == root ) return NULL;
    
    if ( root == p || root == q) return root;
    
    struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
    
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);
    
    if ( NULL == left ) return right;
    
    if ( NULL == right ) return left;
    
    if ( left && right ) return root;
    
    return NULL;
        
}