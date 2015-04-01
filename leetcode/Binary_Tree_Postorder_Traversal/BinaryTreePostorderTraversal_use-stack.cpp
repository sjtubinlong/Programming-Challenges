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
        vector<int> ans;
        if(root == NULL) return ans;
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        TreeNode* last = NULL;
        while(!stk.empty()){
            TreeNode* cur = stk.top();
            if((!cur->left && !cur->right) // 叶子节点
                || (!cur->right && cur->left && cur->left == last) // 无右子节点，刚访问过左子节点
                || (cur->right && cur->right == last) // 有右子节点，且刚访问过
                ){
                    last = cur;
                    ans.push_back(cur->val);
                    stk.pop();
                }else if((cur->left && cur->left != last // 有左子结点且左子结点没有被刚访问过
                        && (!cur->right || cur->right != last)) // 无右子节点或右子节点没有被刚访问过
                ){
                    stk.push(cur->left);
                }else if((cur->right && cur->right != last) // 有右子节点，且没有被刚访问过
                        && (!cur->left || cur->left == last) // 无左子结点或左子结点刚被访问过
                ){
                    stk.push(cur->right);
                }
        }
        return ans;
    }
};

