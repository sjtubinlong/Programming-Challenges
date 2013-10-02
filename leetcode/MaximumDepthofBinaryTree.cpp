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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
        int step = 0;
        dfs(root,step,max);
        return max;
    }
    void dfs(TreeNode* root, int step, int&max)
    {
        if(root==NULL)
        {
            if(step>max)
            {
                max = step;
            }
            return;
        }
        dfs(root->left,step+1,max);
        dfs(root->right,step+1,max);
    }
};