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
    void dfs(TreeNode* root, int depth, int &ans){
        if(root == NULL){
            if(depth == 1) ans = 0;
            return;
        }
        if(!root->left && !root->right){
            ans = min(ans, depth);
            return;
        }
        dfs(root->left, depth+1, ans);
        dfs(root->right, depth+1, ans);
    }
    int minDepth(TreeNode *root) {
        int ans = INT_MAX;
        dfs(root, 1, ans);
        return ans;
    }
};
