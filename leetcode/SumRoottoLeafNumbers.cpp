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
    int sumNumbers(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int sum = 0;
        dfs( root, 0, sum );
        return sum;
    }
    void dfs( TreeNode* root, int cur, int & sum ){
        if( root==NULL ){
            return;
        }
        cur = cur*10 + root->val;
        if( root->left==NULL && root->right==NULL ){
            sum += cur;
            return;
        }
        dfs( root->left, cur, sum );
        dfs( root->right, cur, sum );
    }
};