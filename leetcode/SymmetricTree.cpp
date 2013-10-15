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
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root==NULL) return true;
        vector<TreeNode*> cur;
        vector<TreeNode*> pre;
        vector<int> val;
        cur.push_back(root);
        val.push_back( root->val );
        while( !cur.empty() ){
           if( !check(val) ) return false;
           pre = cur;
           cur.clear();
           val.clear();
           for( int i = 0; i < pre.size(); ++i ){
               if( pre[i]->left ){
                   cur.push_back(pre[i]->left);
                   val.push_back(pre[i]->left->val);
               }else val.push_back(0);
               if( pre[i]->right ){
                   cur.push_back(pre[i]->right);
                   val.push_back(pre[i]->right->val);
               }else val.push_back(0);
           }
        }
        return true;
    }
    bool check( vector<int> & vec ){
        int i = 0;
        int j = vec.size()-1;
        while( i < j ){
            if( vec[i] != vec[j] ) return false;
            ++i;
            --j;
        }
        return true;
    } 
};