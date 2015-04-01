// The solution will change the binary tree
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
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* cur = stk.top();
            if(!cur->left){
                ans.push_back(cur->val);
                stk.pop();
                if(cur->right){
                    stk.push(cur->right);
                    cur->right = NULL;
                }
            }else{
                stk.push(cur->left);
                cur->left = NULL;
            }
        }
        return ans;
    }
};
