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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( l1==NULL ) return l2;
        if( l2==NULL ) return l1;
        
        ListNode *L0;
        ListNode *cur0, *cur1, *cur2;
        if( l1->val < l2->val ){
            L0 = l1;
            cur1 = l1->next;
            cur2 = l2;
        }else{
            L0 = l2;
            cur1 = l1;
            cur2 = l2->next;
        }
        cur0 = L0;
        while( cur1 != NULL && cur2 != NULL ){
            if( cur1->val < cur2->val ){
                cur0->next = cur1;
                cur1 = cur1->next;
            }else{
                cur0->next = cur2;
                cur2 = cur2->next;
            }
            cur0 = cur0->next;
        }
        if( cur1 != NULL ){
            cur0->next = cur1;
        }
        if( cur2 != NULL ){
            cur0->next = cur2;
        }
        return L0;
    }
};