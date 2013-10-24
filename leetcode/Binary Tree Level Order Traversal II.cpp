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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector< vector<int> > result;
        if( root==NULL ) return result;
        vector<int> vec;
        vector< TreeNode* > cur;
        vector< TreeNode* > pre;
        cur.push_back( root );
        vec.push_back( root->val );
        while( !cur.empty() ){
            result.push_back( vec );
            vec.clear();
            pre = cur;
            cur.clear();
            for( int i = 0; i < pre.size(); ++i ){
                if( pre[i]->left ){
                    cur.push_back( pre[i]->left );
                    vec.push_back( pre[i]->left->val );
                }
                if( pre[i]->right ){
                    cur.push_back( pre[i]->right );
                    vec.push_back( pre[i]->right->val );
                }
            } 
        }
        reverse( result.begin(), result.end() );
        return result;
    }
};