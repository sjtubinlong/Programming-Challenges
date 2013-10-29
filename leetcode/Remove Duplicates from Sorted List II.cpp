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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if( !head || !head->next ) return head;
        bool unique = true;
        ListNode* ptr = head;
        ListNode* newHead = NULL;
        ListNode* curNode = NULL;
        while( ptr ){
            ListNode* temp = ptr->next;
            if( ptr->next==NULL && unique ){
                if( newHead==NULL ){
                    newHead = ptr;
                }else{
                    curNode->next = ptr;
                }
                break;
            }
            if( ptr->next != NULL ){
                if( ptr->val == ptr->next->val ) unique = false;
                else{
                    if( unique ){
                        if( newHead==NULL ){
                            newHead = ptr;
                            curNode = ptr;
                            curNode->next = NULL;
                        }else{
                            curNode->next = ptr;
                            curNode = curNode->next;
                            curNode->next = NULL;
                        }
                    }else unique = true;
                }
            }
            ptr = temp;
        }
        return newHead;
    }
};