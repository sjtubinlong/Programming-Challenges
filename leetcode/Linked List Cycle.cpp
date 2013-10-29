/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if( head==NULL || head->next==NULL ) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        do{
            if( !slow || !fast ) return false;
            slow = slow->next;
            fast = fast->next;
            if( !fast ) return false;
            fast = fast->next;
        }while( slow != fast );
        return true;
    }
};