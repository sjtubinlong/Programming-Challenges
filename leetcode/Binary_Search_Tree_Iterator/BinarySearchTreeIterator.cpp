/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> s;
    TreeNode* current;
    
    BSTIterator(TreeNode *root) {
        current = root;
    }
    
    void traverse(TreeNode* root){
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty() || current;
    }

    /** @return the next smallest number */
    int next() {
        while(!s.empty() || current){
            if(current){
                s.push(current);
                current = current->left;
            }else{
                current = s.top()->right;
                break;
            }
        }
        TreeNode* ret = s.top();
        s.pop();
        return ret->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
