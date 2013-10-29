class Solution {
public:
    int longestValidParentheses(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = s.size();
        stack<int> stk;
        for( int i = 0; i < n; ++i ) {
            if( s[i] == '(' ){
                stk.push(i);
            }else{
                if( !stk.empty() ){
                    s[i] = '.';
                    s[ stk.top() ] = '.';
                    stk.pop();   
                }
            }
        }
        int maxLen = 0;
        int curLen = 0;
        for( int i = 0; i < n; ++i ){
            if( s[i]=='.' ) ++curLen;
            else curLen = 0;
            if( curLen > maxLen ) maxLen = curLen;
        }
        return maxLen;
    }
};