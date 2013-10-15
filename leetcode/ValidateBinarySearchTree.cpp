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
    bool isValidBST(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return dfs( root,  INT_MAX, INT_MIN );
    }
    bool dfs( TreeNode* root, int max, int min ){
        if( root==NULL ) return true;
        if( root->val <= min || root->val >= max ) return false;
        if( !dfs( root->left, root->val, min) ) return false;
        if( !dfs( root->right, max, root->val ) ) return false;
        return true;
    }
};