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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( head==NULL || m==n ) return head;
        ListNode* pre = head;
        int k = 1;
        while( k < m-1 ){
            if( pre==NULL ) break;
            pre = pre->next;
            ++k;
        }
        if( pre==NULL ) return head;
        if( m==1 ) pre = NULL;
        ListNode* cur;
        if( pre != NULL ) cur = pre->next;
        else cur = head;
        if( cur==NULL ) return head;
        ListNode* curTail = cur;
        ListNode* it = cur->next;
        k = m;
        while(  k < n  ){
            if( it==NULL ) break;
            ListNode* tmp = it->next;
            it->next = cur;
            cur = it;
            it = tmp;
            ++k;
        }
        if( pre!=NULL ) pre->next = cur; 
        curTail->next = it;
        if( pre==NULL ) return cur;
        return head;
    }
};