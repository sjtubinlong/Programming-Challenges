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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode* slow = head;
        ListNode* fast = head;
        do{
            if( !slow || !fast ) return NULL;
            slow = slow->next;
            fast = fast->next;
            if( fast ) fast = fast->next;
            else return NULL;
        }while( slow != fast );
        slow = head;
        while( slow != fast ){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};