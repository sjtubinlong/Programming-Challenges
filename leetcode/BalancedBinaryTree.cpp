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
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ht = getHeight(root);
        return ht!=-1;
    }
    int getHeight( TreeNode* root ){
        if( root==NULL ) return 0;
        int lh = getHeight( root->left );
        if( lh==-1 ) return -1;
        int rh = getHeight( root->right );
        if( rh==-1 ) return -1;
        if( abs(lh-rh) > 1 ) return -1;
        return (lh>rh?lh:rh)+1;
    }
};