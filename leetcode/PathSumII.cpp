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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> path;
        vector< vector<int> > result;
        dfs( root, 0, sum, path, result );
        return result;
    }
    void dfs( TreeNode* root, int cur, int target,vector<int> path, vector< vector<int> > &result ){
        if( root==NULL ){
            return;
        }
        path.push_back( root->val );
        cur += root->val;
        if( !root->left && !root->right ){
            if( cur==target ){
                result.push_back(path);
                return;
            }
        }
        dfs( root->left, cur, target, path, result );
        dfs( root->right, cur, target, path, result );
    }
};