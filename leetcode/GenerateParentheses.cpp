class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        if( n==0 ) return result;
        stack<char> stk;
        string cur(2*n, '.');
        dfs( 0, n, cur, result, stk );
        return result;
    }
    void dfs( int k, int n, string& cur, vector<string>& result, stack<char>& stk )
    {
        if( k == 2*n )
        {
            if( !stk.empty() )
            {
                return;
            }
            result.push_back(cur);
            return;
        }
        cur[k] = '(';
        stk.push(cur[k]);
        dfs( k+1, n, cur, result, stk );
        if( !stk.empty() ) stk.pop();//backtrace
        cur[k] = ')';
        if( stk.empty() ) return;
        char c = stk.top();
        stk.pop();
        if( c != '(' ) return;
        dfs( k+1, n, cur, result, stk );
        stk.push(c);//backtrace
    }
};