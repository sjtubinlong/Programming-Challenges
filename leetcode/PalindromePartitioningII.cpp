class Solution {
public:
    int minCut(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = s.size();
        vector< vector<bool> > map(n, vector<bool>(n, false) );
        check( s, map );
        vector<int> dp(n, 0);
        dp[n-1] = 0;
        for( int i = n-2; i>=0; --i ){
            dp[i] = n - i - 1;
            for( int j = i; j < n; ++j ){
                if( map[i][j] ){
                    if( j + 1 < n && dp[j+1] + 1 < dp[i] )
                        dp[i] = dp[j+1] + 1;
                    else if( j + 1 == n ){
                        dp[i] = 0;
                    }
                }
            }
        }
        return dp[0];
    }
    void check( string& s, vector< vector<bool> >& map ){
        int n = s.size();
        for( int i = 0; i != n; ++i ){
            map[i][i] = true;
            if( i+1 < n && s[i]==s[i+1] ){
                map[i][i+1] = true;
            }
        }
        for( int len = 3; len <= n; ++len ){
            for( int i = 0; i < n-len+1; ++i ){
                int j = i + len - 1;
                if( map[i+1][j-1] && s[i]==s[j] ){
                    map[i][j] = true;
                }
            }
        }
    }
};