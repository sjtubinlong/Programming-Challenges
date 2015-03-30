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
    int dfs(TreeNode* root, bool& balanced){
        if(root == NULL) return 0;
        if(!root->left && !root->right) return 1;
        bool lbalanced = true;
        bool rbalanced = true;
        int ldepth = dfs(root->left, lbalanced);
        int rdepth = dfs(root->right, rbalanced);
        balanced = lbalanced && rbalanced;
        if(abs(ldepth - rdepth) > 1) balanced = false;
        return max(ldepth, rdepth) + 1;
    }
    bool isBalanced(TreeNode *root) {
        bool ans = true;
        dfs(root, ans);
        return ans;
    }
};
