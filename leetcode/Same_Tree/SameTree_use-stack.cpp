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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if( p == q ) return true;
        if( p == NULL || q == NULL ) return false;
        stack<TreeNode*> stk;
        stk.push(p);
        stk.push(q);
        while(!stk.empty()){
            TreeNode *_p = stk.top(); stk.pop();
            TreeNode *_q = stk.top(); stk.pop();
            
            if( !_p && !_q) continue;
            if( !_p || !_q) return false;
            
            if(_p->val != _q->val){
                return false;
            }
            stk.push(_p->left); stk.push(_q->left);
            stk.push(_p->right); stk.push(_q->right);
        }
        return true;
    }
};
