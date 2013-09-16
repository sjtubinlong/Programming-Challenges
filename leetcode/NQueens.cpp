class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<string> > result;
        if(n==0)
        {
            return result;
        }
        vector<int> queen(n);
        vector<string> solution(n,string(n,'.'));
        dfs( queen, n, 0, result, solution );
        return result;
    }
    void dfs( vector<int>& queen, int n, int step, vector< vector<string> >& result,vector<string>& asolution )
    {
        if(step==n)
        {
            result.push_back(asolution);
            return;
        }
        for(int i = 0; i != n; ++i )
        {
            bool valid = true;
            for( int j = 0; j <= step-1; ++j )
            {
                if( abs(step-j)==abs(i-queen[j]) || i==queen[j] )
                {
                    valid = false;
                    break;
                }
            }
            if( valid )
            {
                queen[step] = i;
                asolution[step][i] = 'Q';
                dfs(queen, n, step+1, result, asolution);
                asolution[step][i] = '.';
            }
        }
    }
};