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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int l1, int r1, int l2, int r2){
        if(l1 > r1 || l2 > r2) return NULL;
        int x = preorder[l1];
        int i = l2;
        for(; i <= r2; ++i){
            if(inorder[i] == x){
                break;
            }
        }
        TreeNode *root = new TreeNode(x);
        root->left = buildTree(preorder, inorder, l1 + 1, l1  + i - l2, l2, i - 1);
        root->right = buildTree(preorder, inorder, l1 + i - l2 + 1, r1, i + 1, r2);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        int m = inorder.size();
        if(n == 0 || m == 0 || n != m) return NULL;
        return buildTree(preorder, inorder, 0, n - 1, 0, m - 1);
    }
};
