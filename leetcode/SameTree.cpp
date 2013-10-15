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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( p==q ) return true;
        if( p==NULL || q==NULL ) return false;
        if( p->val != q->val ) return false;
        return isSameTree( p->left, q->left )&&isSameTree( p->right, q->right );
    }
};