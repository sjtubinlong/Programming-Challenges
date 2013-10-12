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
    ListNode *swapPairs(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( head==NULL || head->next ==NULL ) return head;
        ListNode* first = head, *second = head->next;
        ListNode* iter = second->next;
        ListNode* pre = NULL;
        while( first != NULL )
        {   
            if( second==NULL ) break;
            second->next = first;
            first->next = iter;
            if( pre==NULL ) {
                head = second;
            } else{
                pre->next = second;   
            }
            pre = first;
            first = iter;
            if( iter != NULL ){
                second = iter->next;
            }
            if( second != NULL ){
                iter = second->next;
            }else iter = NULL;
        }
        return head;
    }
};