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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int l1, int r1, int l2, int r2){
        if(l1 > r1 || l2 > r2 ) return NULL;
        int x = postorder[r2];
        int i = l1;
        for(; i <= r1; ++i){
            if(inorder[i] == x) break;
        }
        TreeNode *root = new TreeNode(x);
        root->left = buildTree(inorder, postorder, l1, i-1, l2, l2 + i - 1 - l1);
        root->right = buildTree(inorder, postorder, i + 1, r1, l2 + i - l1, r2 - 1);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        int m = postorder.size();
        if(n == 0 || m == 0 || n != m) return NULL;
        return buildTree(inorder, postorder, 0, n - 1, 0, m-1);
    }
};
