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
        TreeNode *cur = root;
        while(cur){
            if(cur->left == NULL){
                cur = cur->right;
            }else{
                if(cur->right) {
                    TreeNode *p = cur->left;
                    while(p->right) p = p->right;
                    p->right = cur->right;
                }
                cur-> right = cur->left;
                cur->left = NULL;
            }
        }
    }
};
