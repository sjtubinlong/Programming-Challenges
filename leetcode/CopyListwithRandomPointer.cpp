#include <unordered_set>
using namespace std;

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };
 
class Solution {
public:
    static RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( head==NULL ) return NULL;
        RandomListNode* newHead = NULL;
        unordered_set<RandomListNode*> occur;
        occur.insert(head);
        dfs( newHead, head, occur );
        return newHead;
    }
    static void dfs( RandomListNode*&cur, RandomListNode* node, unordered_set<RandomListNode*>& occur ){
        if( node==NULL ) return;
        cur = new RandomListNode( node->label );
        if( node->next && occur.find(node->next)!=occur.end() ){
            occur.insert(node->next);
            dfs( cur->next, node->next, occur );
        }
        if( node->random && occur.find(node->random)!=occur.end() ){
            occur.insert(node->random);
            dfs( cur->random, node->random, occur );
        }
    }
};

int main()
{
    RandomListNode head(-1), nhead(-3),rhead(-2);
    head.next = &nhead;
    head.random = &rhead;
    Solution::copyRandomList(head);
    return 0; 
}