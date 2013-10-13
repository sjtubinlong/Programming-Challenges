class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( needle[0]=='\0' ) return haystack;
        int n = strlen(haystack);
        int m = strlen(needle);
        vector<int> P( m+1, -1 );
        pre_handle( needle, P );
        int j = 0;
        int i = 0;
        while( haystack[i] != '\0' )
        {
           while( j>=0 && needle[j] != haystack[i] ) j = P[j];
           ++i;
           ++j;
           if ( needle[j]=='\0' )
           {
              return haystack+i-j;
           }
        }
        return NULL;
    }
    void pre_handle( char* B, vector<int>& P )
    {
        P[0] = -1 ;
        int i = 0;
        int j = -1;
        while( B[i] != '\0' )
        {
            while( j>=0 && B[j]!=B[i] ){
                j = P[j];
            }
            ++i;
            ++j;
            P[i] = B[i] == B[j] ? P[j] : j;
        }
    }
};