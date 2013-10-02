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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTree( preorder,0,preorder.size()-1, inorder,0, inorder.size()-1 );
    }
    TreeNode* buildTree( vector<int> &preorder, int preLeft, int preRight, vector<int> &inorder, int iLeft, int iRight )
    {
        if( preRight-preLeft<0 || iRight-iLeft<0 )
        {
            return NULL;
        }
        int cur = preorder[preLeft];
        int idx = 0;
        for( idx = iLeft; idx <= iRight; ++idx )
        {
            if( inorder[idx]==cur )
            {
                break;
            }
        }
        TreeNode* root = new TreeNode(cur);
        if( idx-1 >= iLeft )
            root->left = buildTree( preorder, preLeft+1, preLeft+1+idx-iLeft-1, inorder, iLeft, idx-1 );
        if( iRight-idx-1>=0 )
            root->right = buildTree( preorder, preLeft+idx-iLeft+1, preRight, inorder, idx+1, iRight);
        return root;
    }
};