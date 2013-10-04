class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( s.size()==0 ) return 0;
        vector<int> hash( 256, -1 );
        hash[ s[0] ] = 0;
        int curLen = 1;
        int maxLen = 1;
        for( int i = 1; i != s.size(); ++i ){
            if( hash[ s[i] ]==-1 || hash[ s[i] ] < i-curLen ){
                curLen = curLen + 1;
            }else{
                curLen = i-hash[ s[i] ];
            }
            if( curLen > maxLen ){
                maxLen = curLen;
            }
            hash[ s[i] ] = i;
        }
        return maxLen;
    }
};