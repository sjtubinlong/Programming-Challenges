class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n==1 )
        {
            return true;
        }
        int maxDist = A[0];
        for( int i = 1; i != n; ++i )
        {
            if( maxDist < i )
            {
                return false;
            }
            if( maxDist>=n-1 )
            {
                return true;
            }
            if( maxDist >= i )
            {
                if( i+A[i] > maxDist )
                {
                    maxDist = i+A[i];
                }
            }
        }
        return false;
    }
};