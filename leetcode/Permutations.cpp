class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > result;
        vector<int> status( num.size(), 0 );
        vector<int> tmp( num.size(), 0 );
        dfs( result, num, tmp, status, 0);
        return result;
    }
    void dfs( vector<vector<int> > & result, vector<int>& num, vector<int>& tmp, vector<int>& status, int k )
    {
        if( k==num.size() )
        {
            result.push_back(tmp);
        }
        for( int i = 0; i != num.size();++i )
        {
            if(status[i]==0)
            {
                tmp[k] = num[i];
                status[i] = 1;
                dfs( result, num, tmp,status, k+1 );
                status[i] = 0;
            }
        }
    }
};