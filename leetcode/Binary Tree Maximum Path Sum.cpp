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
    int maxPathSum(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if( root == NULL ) return 0;
        int maxSum =  root->val;
        dfs( root, maxSum );
        return maxSum;
    }
    int dfs( TreeNode* cur, int & maxSum ){
        if(cur==NULL){
            return 0;
        }
        int lSum = dfs( cur->left, maxSum );
        int rSum = dfs( cur->right, maxSum );
        int ret = max( cur->val, max( lSum, rSum ) + cur->val );
        if( maxSum < ret ) maxSum = ret;
        if( maxSum < lSum + rSum + cur->val ) maxSum = lSum + rSum + cur->val;
        return ret;
    }
};