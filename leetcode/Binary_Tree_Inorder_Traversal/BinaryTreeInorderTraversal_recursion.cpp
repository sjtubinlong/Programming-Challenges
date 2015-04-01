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
    void inorderTraversal(TreeNode *root, vector<int> &ans){
        if(root == NULL) return;
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        inorderTraversal(root, ans);
        return ans;
    }
};
