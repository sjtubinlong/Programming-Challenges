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
    vector<TreeNode *> generateTrees(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return CreateBST( 1, n );
        
    }
    vector<TreeNode*> CreateBST( int _from, int _to ){
        vector<TreeNode*> result;
        if( _from > _to ) {
            result.push_back(NULL);
            return result;
        };
        if( _from == _to ){
            result.push_back( new TreeNode(_from) );
            return result;
        }
        for( int i = _from; i <= _to; ++i ){
            vector<TreeNode*> leftTrees = CreateBST( _from, i-1 );
            vector<TreeNode*> rightTrees = CreateBST( i+1, _to );
            for( int j = 0; j < leftTrees.size(); ++j ){
                for( int k = 0; k < rightTrees.size(); ++k ){
                    TreeNode* cur = new TreeNode(i);
                    cur->left = leftTrees[j];
                    cur->right = rightTrees[k];
                    result.push_back(cur);
                }
            }
        }
        return result;
    }
};