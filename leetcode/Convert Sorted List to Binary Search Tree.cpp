/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if( head==NULL ) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tail = slow;
        while( fast->next ){
            tail = slow;
            slow = slow->next;
            fast = fast->next;
            if( fast->next ) fast = fast->next;
        }
        tail->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        ListNode* cur = slow->next;
        if( head != slow )
            root->left = sortedListToBST( head );
        root->right = sortedListToBST( cur );
        return root;
    }
};