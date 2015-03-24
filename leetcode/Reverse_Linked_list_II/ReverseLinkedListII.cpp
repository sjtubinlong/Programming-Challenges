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
        if(head == NULL || head->next == NULL) return head;
        ListNode *cut = NULL, *prev = head, *cur = head->next;
        int count = 1;
        while(count < m && cur != NULL){
            count++;
            if(cut == NULL) cut = head;
            else cut = cut->next;
            cur = cur->next;
            prev = prev->next;
        }
        ListNode *_head = prev;
        ListNode *_tail = prev;
        while(count < n && cur != NULL){
            ListNode *_cur = cur->next;
            cur->next = prev;
            prev = cur;
            cur = _cur;
            _head = prev;
            count++;
        }
        if(cut == NULL){
            _tail->next = cur;
            return _head;
        }
        cut->next = _head;
        _tail->next = cur;
        return head; 
        
    }
};
