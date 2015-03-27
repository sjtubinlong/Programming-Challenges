// Maximum Subarray + DFS
// The solution is similar to solve Maximum Subarry with Divide and Conquer strategy
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
    int dfs(TreeNode *root, int& maxSum){
        if(root == NULL){
            return 0;
        }
        int lsum = dfs(root->left, maxSum);
        int rsum = dfs(root->right, maxSum);
        int ret = max(root->val, max(lsum, rsum) + root->val);
        if(maxSum < ret) maxSum = ret;
        if(maxSum < lsum + rsum + root->val) maxSum = lsum + rsum + root->val;
        return ret;
    }
    
    int maxPathSum(TreeNode *root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
};
