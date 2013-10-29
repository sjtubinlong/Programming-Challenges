/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if( !root ) return;
        vector<TreeLinkNode*> cur, pre;
        cur.push_back( root );
        while( !cur.empty() ){
            pre = cur;
            cur.clear();
            for( int i = 0; i < pre.size(); ++i ){
                if( i+1 < pre.size() ) pre[i]->next = pre[i+1];
                if( pre[i]->left ) cur.push_back( pre[i]->left );
                if( pre[i]->right )cur.push_back( pre[i]->right );
            }
        }
    }
};