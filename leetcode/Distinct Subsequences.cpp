class Solution {
public:
    int numDistinct(string S, string T) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = S.size();
        int m = T.size();
        if( n==0 ) return 0;
        if( m==0 ) return 1;
        vector< vector<int> > dp( n+1, vector<int>(m+1, 0) );
        for( int i = 0; i <= n; ++i ){
            dp[i][m] = 1;
        }
        for( int i = n-1; i >= 0; --i ){
            for( int j = m-1; j >= 0; --j ){
                if( S[i]==T[j] ){
                    dp[i][j] = dp[i+1][j] + dp[i+1][j+1];
                }else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};