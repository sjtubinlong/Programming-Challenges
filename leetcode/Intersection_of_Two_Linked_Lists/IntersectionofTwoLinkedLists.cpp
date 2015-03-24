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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode *p1 = headA, *p2 = headB;
        int len1 = 0, len2 = 0;
        while(p1 != NULL){
            len1++;
            p1 = p1->next;
        }
        while(p2 != NULL){
            len2++;
            p2 = p2->next;
        }
        p1 = headA, p2 = headB;
        while(len1 > len2){
            len1--;
            p1 = p1->next;
        }
        while(len2 > len1){
            len2--;
            p2 = p2->next;
        }
        while(p1 != NULL && p2 != NULL){
            if(p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};
