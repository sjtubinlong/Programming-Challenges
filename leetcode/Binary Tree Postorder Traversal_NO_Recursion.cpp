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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        if( root==NULL ) return result;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* prev = NULL;
        while( !stk.empty() ){
             TreeNode* cur = stk.top();
             if( (cur->left!=NULL && prev!=cur->left) && ( prev!=cur->right || !prev ) ){
                 stk.push(cur->left);
             }else if( cur->right!=NULL && prev != cur->right ){
                 stk.push(cur->right);
             } else {
                 stk.pop();
                 prev = cur;
                 result.push_back(cur->val);
             }
        }
        return result;
    }
};