class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        int maxLen = 1;
        int start = 0;
        vector< vector<bool> > flag( n, vector<bool>(n,false) );
        for( int i = 0; i != n; ++i ){
            flag[i][i] = true;
            if( i+1<n && s[i]==s[i+1]){
                flag[i][i+1] = true;
                maxLen = 2;
                start = i;
            }
        }
        for( int len = 3; len <= n; ++len ){
            for( int x = 0; x < n-len+1; ++x ){
                int y = x + len - 1;
                if( flag[x+1][y-1] && s[x]==s[y] ){
                    flag[x][y] = true;
                    maxLen = len;
                    start = x;
                }
                
            }
        }
        return s.substr( start, maxLen );
    }
};