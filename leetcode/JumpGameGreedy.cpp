class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result( n, 0 );
        result[0] = 1;
        for( int i = 0; i != n; ++i )
        {
            if( result[i]==0 ) continue;
            for( int j = i+1; j <= i+A[i]; ++j )
            {
                if( result[j]==1 )continue;
                if( j+A[j]>=n-1 )
                {
                    return true;
                }
                result[j] = 1;
            }
            if( result[n-1]==1 )
            {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result( n, 0 );
        for( int i = 0; i != n; ++i )
        {
            result[i] = i+A[i];
            for( int j = i-1; j >=0; --j )
            {
                if( j+ A[j] >= i && result[j]<result[i])
                {
                    result[j] = result[i];
                }
            }
            if( result[0]>=n-1 )
            {
                return true;
            }
        }
        return false;
    }
};