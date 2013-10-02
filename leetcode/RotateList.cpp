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
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( head==NULL || k == 0 ) return head;
        ListNode* pre;
        ListNode* post;
        pre = post = head;
        for( int i = 0; i != k ; ++i ){
            if( post == NULL ){
                post = head;
            }
            post = post->next;
        }
        if( post==NULL ) return head;
        while( post->next != NULL ){
            pre = pre->next;
            post = post->next;
        }
        ListNode *newHead = pre->next;
        pre->next = NULL;
        post->next = head;
        head = newHead;
        return newHead;
    }
};