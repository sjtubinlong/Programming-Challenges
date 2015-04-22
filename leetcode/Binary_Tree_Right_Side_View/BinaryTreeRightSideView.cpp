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
        
        vector<TreeNode*> pre, cur;
        cur.push_back(root);
        while(cur.size() != 0){
            pre = cur;
            cur.clear();
            for(int i = 0; i < pre.size(); ++i){
                if(pre[i]->left) cur.push_back(pre[i]->left);
                if(pre[i]->right) cur.push_back(pre[i]->right);
            }
            ans.push_back(pre.back()->val);
        }
        return ans;
    }
};
