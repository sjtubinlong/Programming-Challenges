// Pay attention to the last NULL
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
        
        queue<TreeNode*> Q;
        vector<int> data;
        
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            TreeNode* cur = Q.front();
            Q.pop();
            if(cur == NULL){
                ans.push_back(data);
                data.clear();
                if(Q.empty()) {
                    break;
                }else{
                    Q.push(NULL);
                    continue;
                }
            }
            data.push_back(cur->val);
            if(cur->left) Q.push(cur->left);
            if(cur->right) Q.push(cur->right);
        }
        return ans;
    }
};
