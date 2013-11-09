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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        if( root==NULL ) return result;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while( cur ){
            stk.push( cur );
            result.push_back( cur->val );
            cur = cur->left;
        }
        while( !stk.empty() ){
            TreeNode* cur = stk.top();
            stk.pop();
            if( cur->right ){
                cur = cur->right;
                while( cur ){
                    stk.push(cur);
                    result.push_back( cur->val );
                    cur = cur->left;
                }
            }
        }
        return result;
    }
};