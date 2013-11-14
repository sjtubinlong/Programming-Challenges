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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if( !head || !head->next ) return head;
        ListNode* cur = head->next;
        head->next = NULL;
        while ( cur ){
            ListNode* newCur = cur->next;
            if( head->val >= cur->val ){
                cur->next = head;
                head = cur;
                cur = newCur;
                continue;
            }
            ListNode* ptr = head;
            while( ptr->next && ptr->next->val < cur->val ){
                ptr = ptr->next;
            }
            cur->next = ptr->next;
            ptr->next = cur;
            cur = newCur;
        }
        return head;
    }
};