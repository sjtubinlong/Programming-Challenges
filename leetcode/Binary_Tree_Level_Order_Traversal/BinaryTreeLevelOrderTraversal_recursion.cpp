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
    void dfs(TreeNode *root, int level, vector< vector<int> > &ans){
        if(root == NULL) return;
        if(ans.size() <= level){
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);
        dfs(root->left, level+1, ans);
        dfs(root->right, level+1, ans);
    }
    
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector< vector<int> > ans;
        dfs(root, 0, ans);
        return ans;
    }
};
