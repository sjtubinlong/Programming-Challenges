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
    void recoverTree(TreeNode *root) {
        if(root == NULL) return;
        
        stack<TreeNode*> q;
        TreeNode* n1 = NULL;
        TreeNode* n2 = NULL;
        TreeNode* pre = NULL;
        TreeNode* cur = root;
        
        while(!q.empty() || cur){
            if(cur){
                q.push(cur);
                cur = cur->left;
            }else{
                cur = q.top();
                q.pop();
                if(pre && pre->val >= cur->val){
                    if(n1 == NULL) {
                        n1 = pre;
                        n2 = cur;
                    }else{
                        n2 = cur;
                    }
                }
                pre = cur;
                cur = cur->right;
            }
        }
        if(n1 && n2){
            n1->val = n1->val + n2->val;
            n2->val = n1->val - n2->val;
            n1->val = n1->val - n2->val;
        }
    }
};
