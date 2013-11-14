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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if( !head || !head->next || !head->next->next ) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while( fast->next != NULL ){
            slow = slow->next;
            fast = fast->next;
            if( !fast->next ) break;
            fast = fast->next;
        }
        if( !slow || !fast ) return;
        
        ListNode* cur = slow->next;
        //cut down into two part from the middle
        slow->next = NULL;
        if( cur==NULL ) return;
        //reverse the second half
        ListNode* tmp = cur;
        ListNode* nxt = cur->next;
        while( nxt ){
            ListNode* newCur = nxt->next;
            nxt->next = cur;
            cur = nxt;
            nxt = newCur;
        }
        tmp->next = NULL;
        //combine the two parts
        ListNode* preHalf = head;
        ListNode* nxtHalf = cur;
        while( preHalf && nxtHalf ){
            ListNode* newPre = preHalf->next;
            ListNode* newNxt = nxtHalf->next;
            preHalf->next = nxtHalf;
            nxtHalf->next = newPre;
            preHalf = newPre;
            nxtHalf = newNxt;
        }
    }
};