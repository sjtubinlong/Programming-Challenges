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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector< vector<int> > ans;
        
        if(root == NULL) return ans;
        
        vector<TreeNode*> cur;
        vector<int> data;
        
        cur.push_back(root);
        data.push_back(root->val);
        
        while(cur.size() != 0){
            
            vector<TreeNode*> pre = cur;
            ans.push_back(data);
            cur.clear();
            data.clear();
            for(int i = 0; i < pre.size(); ++i){
                if(pre[i]->left) {
                    cur.push_back(pre[i]->left);
                    data.push_back(pre[i]->left->val);
                }
                if(pre[i]->right) {
                    cur.push_back(pre[i]->right);
                    data.push_back(pre[i]->right->val);
                }
            }
        }
        return ans;
    }
};
