class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( m==0 || n==0 ) return 0;
        vector< vector<int> > dp( m, vector<int>(n, 0) );
        dp[0][0] = 1;
        for( int i = 1; i != n; ++i ){
            dp[0][i] = 1;
        }
        for( int i = 1; i != m; ++i ){
            dp[i][0] = 1;
        }
        for( int i = 1; i != m; ++i ){
            for( int j = 1; j != n; ++j ){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};