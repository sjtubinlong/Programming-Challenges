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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( n<=0 || head==NULL ) return head;

        ListNode* pre = head;
        ListNode* last = head;
        for( int i = 0; i < n; ++i )
        {
            if( last->next==NULL )
            {
                if( i==n-1 )
                {
                    ListNode* newHead = head->next;
                    delete head;
                    head = newHead;
                }
                return head;
            }
            last = last->next;
        }
        while( last->next != NULL )
        {
            pre = pre->next;
            last = last->next;
        }
        ListNode* toDel = pre->next;
        pre->next = toDel->next;
        delete toDel;
        return head;
    }
};