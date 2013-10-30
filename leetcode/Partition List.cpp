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
    ListNode *partition(ListNode *head, int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if( head==NULL || head->next==NULL ) return head;
        ListNode* ptr = head;
        ListNode* pre = NULL, *cur = head;
        while( ptr != NULL ){
            while( ptr->val < x ){
               pre = ptr;
               cur = ptr->next;
               ptr = ptr->next;
               if( ptr==NULL ) break;
            }
            while( ptr != NULL && ptr->next != NULL ){
                if( ptr->next->val >= x ){
                    ptr = ptr->next;
                }else{
                    ListNode* temp = ptr->next;
                    ptr->next = ptr->next->next;
                    temp->next = cur;
                    if( pre != NULL ) pre->next = temp;
                    else head = temp;
                    pre = temp;
                }
            }
            if( ptr != NULL ) ptr = ptr->next;
        }
        return head;
    }
};