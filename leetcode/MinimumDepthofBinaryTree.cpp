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
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( root==NULL ) return 0;
        int min = -1;
        dfs( root, 1, min );
        return min;
    }
    void dfs( TreeNode* root, int depth, int& min ){
        if( root==NULL ){
            return;
        }
        if( !root->left && !root->right ){
            if( depth < min || min==-1 ){
                min = depth;
            }
            return;
        }
        dfs( root->left, depth+1, min );
        dfs( root->right, depth+1, min );
    }
};