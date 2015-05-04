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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = NULL;
        ListNode* q = head;
        while(q != NULL){
            if(q->val == val){
                ListNode *r = q->next;
                if(p == NULL){
                    head = q = r;
                }else{
                    p->next = r;
                    q = r;
                }
            }else{
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};
