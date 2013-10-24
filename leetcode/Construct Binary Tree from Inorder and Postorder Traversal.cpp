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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = inorder.size();
        int m = postorder.size();
        if( n != m || n==0 ) return NULL;
        return buildTree( inorder, 0, n-1, postorder, 0, m-1 );
    }
    TreeNode *buildTree( vector<int> &inorder, int in_from , int in_to, vector<int> &postorder, int post_from, int post_to ){
        if( in_from > in_to || post_from > post_to ) return NULL;
        TreeNode* root = new TreeNode( postorder[post_to] );
        int i;
        for(  i = in_from; i <= in_to; ++i ){
            if( inorder[i]== postorder[post_to] ) break;
        }
        if( i > in_to ) return NULL;
        if( i-1-in_from >= 0 ){
            root->left = buildTree( inorder, in_from, i-1, postorder, post_from, post_from + i-1-in_from );   
        }
        if( in_to - i - 1 >= 0){
            root->right = buildTree( inorder, i+1, in_to, postorder, post_from + i-1-in_from+1, post_to-1 );
        }
        return root;
    }
};