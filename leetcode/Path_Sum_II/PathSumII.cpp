//DFS
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
    void dfs(TreeNode *root, int cur, vector<int>& arr, vector<vector<int> >& ans){
        if(root == NULL) {
            return;
        }
        arr.push_back(root->val);
        cur = cur - root->val;
        
        if(!root->left && !root->right){
            if(cur == 0){
                ans.push_back(arr);
            }
        }
        if(root->left) dfs(root->left, cur, arr, ans);
        if(root->right) dfs(root->right, cur, arr, ans);
        arr.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        vector<int> arr;
        dfs(root, sum, arr, ans);
        return ans;
    }
};
