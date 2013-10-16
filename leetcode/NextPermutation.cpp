class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = num.size();
        if( n==0 || n==1 ) return;
        int cur = n-1;
        while( true ){
            int next = cur--;
            if( num[cur] < num[next] ){
                int pos = n-1;
                while( num[cur] >= num[pos] ) --pos;
                it_swap( num.begin()+cur, num.begin()+pos );
                reverse( num.begin()+next, num.end() );
                return;
            }
            if( cur==0 ){
                reverse( num.begin(), num.end() );
                return;
            }
        }
    }
    void it_swap( vector<int>::iterator it1, vector<int>::iterator it2 ){
        *it1 = *it1^*it2;
        *it2 = *it1^*it2;
        *it1 = *it1^*it2;
    }
};