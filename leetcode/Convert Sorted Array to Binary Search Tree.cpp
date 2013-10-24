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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = num.size();
        if( n==0 ) return NULL;
        return buildTree( num, 0, n-1 );
    }
    TreeNode *buildTree( vector<int> &num, int left, int right ){
        int mid = (left + right)/2;
        TreeNode* root = new TreeNode( num [mid] );
        if( mid-1 >= left ){
            root->left = buildTree( num, left, mid-1 );
        }
        if( mid+1 <= right ){
            root->right = buildTree( num, mid+1, right );
        }
        return root;
    }
};