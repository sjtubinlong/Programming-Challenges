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
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( head==NULL || head->next==NULL ) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while( cur != NULL ){
            if( pre->val == cur->val ){
                ListNode* newCur = cur->next;
                pre->next = newCur;
                delete cur;
                cur = newCur;
            }else{
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};