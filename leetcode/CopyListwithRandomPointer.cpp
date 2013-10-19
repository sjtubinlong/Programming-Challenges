/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( head==NULL ) return NULL;
        RandomListNode* newHead = NULL;
        unordered_map< RandomListNode*, RandomListNode* > occur;
        dfs( newHead, head, occur );
        return newHead;
    }
    void dfs( RandomListNode*&cur, RandomListNode* node, unordered_map<RandomListNode*, RandomListNode* >& occur ){
        if( node==NULL ) return;
        cur = new RandomListNode( node->label );
        if( occur.find(node) == occur.end() ){
            occur[node] = cur;
        }
        if( node->next ){
            if( occur.find(node->next)==occur.end() ){
                dfs( cur->next, node->next, occur );
            }else{
                cur->next = occur[node->next];
            }
        }
        if( node->random ){
            if( occur.find(node->random)==occur.end() ){
                dfs( cur->random, node->random, occur );
            }else{
                cur->random = occur[node->random];
            }
        }
    }
};