class Solution {
public:
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = s.size();
        if( n==0 ) return true;
        if( n%2==1 ) return false;
        stack<char> stk;
        int match[256];
        match['('] = ')';
        match['['] = ']';
        match['{'] = '}';
        for( int i = 0; i != n; ++i )
        {
            if( s[i]=='(' || s[i]=='{' || s[i]=='[' )
            {
                stk.push(s[i]);
            }else{
                if( stk.empty() ) return false;
                char c = stk.top();
                stk.pop();
                if( match[c] != s[i] )
                {
                    return false;
                }
            }
        }
        if( !stk.empty() ) return false;
        return true;
    }
};