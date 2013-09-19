//DFS
class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cur = 0;
        vector<int> map(n,0);
        return dfs( A, n, cur,map);
    }
    bool dfs( int A[], int n, int cur, vector<int>&map )
    {
        if( cur<n && cur+A[cur]>=n-1 )
        {
            return true;
        }
        for( int i = 1; i <= A[cur]; ++i )
        {
            if( map[cur+i] != 1 )
            {
                bool ret = dfs( A, n, cur+i,map);
                if( ret )
                {
                    return ret;
                }
                map[cur+i] = 1;
            }
        }
        return false;
    }
};

//BFS
class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cur = 0;
        vector<int> map(n,0);
        queue<int> Q;
        Q.push(0);
        map[0] = 1;
        while(!Q.empty())
        {
            int cur = Q.front();
            if(cur+A[cur]>=n-1)
            {
                return true;
            }
            Q.pop();
            for( int i = cur+A[cur]; i >cur ; --i )
            {
                if( map[i]==0 )
                {
                    Q.push(i);
                    map[i] = 1;
                }
            }
        }
        return false;
    }
};

