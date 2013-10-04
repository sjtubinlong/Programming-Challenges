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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( l1==NULL ) return l2;
        if( l2==NULL ) return l1;
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p0 = NULL;
        ListNode* cur = NULL;
        bool first = true;
        int v = 0;
        while( p1 != NULL && p2 != NULL ){
            ListNode* newNode = new ListNode(0);
            if( first ){
                p0 = newNode;
                cur = p0;
                first = false;
            }else{
                cur->next = newNode;
                cur = cur->next;
            }
            cur->val = p1->val+p2->val+v;
            v = cur->val/10;
            cur->val %= 10;
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode* remain = p1==NULL?p2:p1;
        while( remain != NULL ){
            ListNode* newNode = new ListNode(0);
            cur->next = newNode;
            cur = cur->next;
            cur->val = remain->val+v;
            v = cur->val/10;
            cur->val %= 10;
            remain = remain->next;
        }
        if( v>0 ){
            ListNode* newNode = new ListNode(0);
            cur->next = newNode;
            cur = cur->next;
            cur->val = v;
        }
        cur->next = NULL;
        return p0;
    }
};