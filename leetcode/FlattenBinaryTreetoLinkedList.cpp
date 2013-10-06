/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( root==NULL ) return;
        queue<TreeNode*> q;
        preOrder( root->left, q );
        preOrder( root->right, q );
        TreeNode* iter = root;
        while( !q.empty() ){
            TreeNode* cur = q.front();
            q.pop();
            iter->left = NULL;
            iter->right = cur;
            iter = cur;
        }
    }
    void preOrder( TreeNode * root, queue<TreeNode*>& q ){
        if( root==NULL ) return;
        q.push(root);
        preOrder( root->left, q );
        preOrder( root->right, q );
    }
};