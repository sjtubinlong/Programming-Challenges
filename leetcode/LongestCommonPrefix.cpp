class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string result;
        int max = 0;
        int n = strs.size();
        if( n==0 ) return result;
        int len = strs[0].size();
        if( len==0 || n==1 ) return strs[0] ;
        for( int i = 1; i < n; ++i ){
            int cnt = 0;
            for( int j = 0; j < len; ++j ){
                if( j >= strs[i].size() || strs[i][j] != strs[0][j] ) break;
                ++cnt;
            }
            if( cnt < max || i==1 ) max = cnt;
        }
        return strs[0].substr( 0, max );
    }
};