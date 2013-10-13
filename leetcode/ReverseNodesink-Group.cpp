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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( head==NULL || head->next==NULL || k <= 1 ) return head;
        ListNode *curHead = head, *curLimit = head;
        for( int i = 0; i < k; ++i ){
            if( curLimit==NULL ) return head;
            curLimit = curLimit->next;
        }
        ListNode *newLimit = curLimit?curLimit->next:NULL;
        ListNode *preTail = NULL;
        bool flag = false;
        while( curHead != NULL&& !flag ){
            ListNode *curTail = curHead;
            ListNode *iter = curHead->next;
            curHead->next = NULL;
            while( iter != curLimit ){
                ListNode *tmp = iter->next;
                iter->next = curHead;
                curHead = iter;
                iter = tmp;
                if( newLimit != NULL )
                    newLimit = newLimit->next;
                else flag = true;
            }
            if( preTail==NULL ) head = curHead;
            else{
                preTail->next = curHead;
            }
            curHead = curLimit;
            curLimit = newLimit;
            preTail = curTail;
            preTail->next = curHead;
            if( curLimit != NULL ){
                newLimit = curLimit->next;
            }
        }
        return head;
    }
};