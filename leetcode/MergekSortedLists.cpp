class Solution {
public:
    static ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = lists.size();
        if( n==0 ) return NULL;
        if( n==1 ) return lists[0];
        vector< ListNode* > vec;
        for( int i = 0; i != n; ++i )
        {
            ListNode* iter = lists[i];
            while( iter != NULL )
            {
                vec.push_back(iter);
                iter = iter->next;
            }
        }
        if( vec.size()==0 ) return NULL;
        sort( vec.begin(), vec.end(), Solution::myfunc );
        for( int i = 0; i != vec.size()-1; ++i ){
            vec[i]->next = vec[i+1];
        }
        vec[vec.size()-1]->next = NULL;
        return vec[0];
    }
    static bool myfunc( ListNode* u, ListNode* v )
    {
        return u->val < v->val;
    }
};