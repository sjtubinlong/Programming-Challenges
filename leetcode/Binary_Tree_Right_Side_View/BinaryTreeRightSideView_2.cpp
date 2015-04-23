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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode* pre = root;
        while(q.size() != 0){
            TreeNode* cur = q.front();
            q.pop();
            if(cur == NULL){
                ans.push_back(pre->val);
                if(!q.empty()) q.push(NULL);
            }else{
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                pre = cur;
            }
        }
        return ans;
    }
};
