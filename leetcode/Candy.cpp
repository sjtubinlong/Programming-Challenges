class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = ratings.size();
        vector<int> candy( n, 1 );
        for( int i = 1; i < n; ++i ){
            if( ratings[i]>ratings[i-1] ){
                candy[i] = max( candy[i-1]+1, candy[i] );
            }
        }
        for( int i = n-2; i >=0; --i ){
            if( ratings[i]>ratings[i+1] ){
                candy[i] = max(candy[i], candy[i+1]+1);
            }
        }
        int total = 0;
        for( int i = 0; i < n; ++i ) total += candy[i];
        return total;
    }
};