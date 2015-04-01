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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        stack<TreeNode *> stk;
        
        TreeNode *cur = root;
        while(!stk.empty() || cur != NULL){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }
            TreeNode *p = stk.top(); stk.pop();
            ans.push_back(p->val);
            cur = p->right;
        }
        return ans;
    }
};
