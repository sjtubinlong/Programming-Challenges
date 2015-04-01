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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        vector<int> data;
        vector<TreeNode*> cur;
        cur.push_back(root);
        bool need_reverse = false;
        while(cur.size() != 0){
            vector<TreeNode*> pre = cur;
            cur.clear();
            for(int i = pre.size() - 1; i >= 0; --i){
                data.push_back(pre[i]->val);
                if(need_reverse){
                    if(pre[i]->right) cur.push_back(pre[i]->right);
                    if(pre[i]->left) cur.push_back(pre[i]->left);
                }else{
                    if(pre[i]->left) cur.push_back(pre[i]->left);
                    if(pre[i]->right) cur.push_back(pre[i]->right);
                }
                
            }
            need_reverse = !need_reverse;
            ans.push_back(data);
            data.clear();
        }
        return ans;
    }
};
