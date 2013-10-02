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
    bool hasPathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool find = false;
        func( root, 0, sum, find );
        return find;
    }
    void func( TreeNode* root, int cur, int target, bool& find ){
        if( root==NULL || find ){
            return;
        }
        cur += root->val;
        if( root->left==NULL && root->right==NULL ){
            if( cur==target ){
                find = true;
            }
            return;
        }
        func( root->left, cur, target, find );
        func( root->right, cur, target, find );
    }
};