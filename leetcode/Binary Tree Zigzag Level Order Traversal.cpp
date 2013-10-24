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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector< vector<int> > result;
        if( root==NULL ) return result;
        
        vector<int> vec;
        vector<TreeNode*> cur;
        vector<TreeNode*> pre;
        cur.push_back(root);
        vec.push_back( root->val );
        bool turn = false;
        while( !cur.empty() ){
            turn = !turn ;
            result.push_back( vec );
            pre = cur;
            vec.clear();
            cur.clear();
            for( int i = pre.size()-1; i >= 0; --i ){
                if( turn ){
                    if( pre[i]->right){
                        cur.push_back( pre[i]->right );
                        vec.push_back( pre[i]->right->val );
                    }
                    if( pre[i]->left ){
                        cur.push_back( pre[i]->left );
                        vec.push_back( pre[i]->left->val );
                    }
                }else{
                    if( pre[i]->left ){
                        cur.push_back( pre[i]->left );
                        vec.push_back( pre[i]->left->val );
                    }
                    if( pre[i]->right){
                        cur.push_back( pre[i]->right );
                        vec.push_back( pre[i]->right->val );
                    }
                }
            }
        }
        return result;
    }
};