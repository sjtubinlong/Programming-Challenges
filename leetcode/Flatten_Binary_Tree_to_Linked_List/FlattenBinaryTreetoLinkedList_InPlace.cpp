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
        if(root == NULL) return;
        if(root->left) flatten(root->left);
        if(root->right) flatten(root->right);
        TreeNode *_rchild = root->right;
        TreeNode *_lchild = root->left;
        root->left = NULL;
        if(_lchild) root->right = _lchild;
        while(_lchild && _lchild->right){
            _lchild = _lchild->right;
        }
        if(_lchild) _lchild->right = _rchild;
        else root->right = _rchild;
    }
};
