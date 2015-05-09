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
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1 == l2) return l1;

        ListNode * head = NULL;
        ListNode * cur = NULL;
        ListNode *p = l1;
        ListNode *q = l2;
        while(p != NULL && q != NULL){
            if(p->val < q->val){
                if(head == NULL) {
                    head = cur = p;
                } else {
                    cur->next = p;
                    cur = p;
                }
                p = p->next;
            }else if(p->val > q->val){
                if(head == NULL){
                    head = cur = q;
                } else {
                    cur->next = q;
                    cur = q;
                }
                q = q->next;
            } else {
                ListNode* t = p->next;
                if(head == NULL){
                    head = cur = p;
                    cur->next = q;
                    cur = q;
                }else{
                    cur->next = p;
                    cur->next->next = q;
                    cur = q;
                }
                p = t;
                q = q->next;
            }
        }
        if(p != NULL) cur->next = p;
        if(q != NULL) cur->next = q;

        return head;
    }

    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode *p = head;
        ListNode *q = head->next;
        while(q != NULL && q->next != NULL){
            p = p->next;
            q = q->next->next;
        }
        ListNode* head2 = p->next;
        p->next = NULL;

        ListNode* l1 = mergeSort(head);
        ListNode* l2 = mergeSort(head2);
        ListNode* newHead = merge(l1, l2);
        return newHead;
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
