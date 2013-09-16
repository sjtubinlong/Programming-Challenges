class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0)
        {
            return 0;
        }
        vector<int> queen(n);
        int result = 0;
        dfs( queen, n, 0, result );
        return result;
    }
    void dfs( vector<int>& queen, int n, int step,int& result )
    {
        if( step==n )
        {
            ++result;
            return;
        }
        for( int i = 0; i != n; ++i )
        {
            bool valid = true;
            for( int j = 0; j != step; ++j )
            {
                if( abs(step-j)==abs(i-queen[j]) || i==queen[j])
                {
                    valid = false;
                    break;
                }
            }
            if(valid)
            {
                queen[step] = i;
                dfs(queen, n, step+1, result );
            }
        }
    }
};