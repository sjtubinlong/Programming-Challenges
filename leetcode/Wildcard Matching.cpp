class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if( !s && !p ) return true;
        if( !s && *p =='\0' ) return true;
        if( !s && *p != '*') return false;
        
        if( !s && *p =='*' ){
            while( *p == '*' ) ++p;
            if( *p == '\0' ) return true;
            return false;
        }
        if( s && !p ) return false;
        
        int n = strlen(s);
        int m = strlen(p);
        int k = 0;
        while( p[k]=='*' ) ++k;
        int num = 0;
        for( ; k < m; ++k ){
            if( p[k] == '*' ) break;
            ++num;
        }
        if( num > n ) return false;
      
        vector< bool > dp( n+2, false );
        dp[ n ] = true;
        int i = m-1;
        for( ; i >= 0; --i ){
            if( p[i] == '*' ){
                while( i > 0 && p[i]==p[i-1] ) --i;
                int j = n;
                for( ; j >=0 && !dp[j]; --j );
                for(; j >=0; --j ) dp[j] = true;
            }else{
                for( int j = 0; j < n+1; ++j )
                    dp[j] = ( p[i]=='?' || p[i]==s[j] )?dp[j+1]:false;
            }
        }
        return dp[0];
    }
};