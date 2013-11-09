class Solution {
public:
    int trap(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if( n <= 2 ) return 0;
        int sum = 0;
        //from left to right
        int cur = 0;
        while( cur < n && A[cur]==0 ) ++cur;
        if( cur >= n ) return 0;
        while( cur < n ){
            int curWater = 0;
            int curHeight = A[cur];
            while( ++cur < n ){
                if( A[cur] >= curHeight ) break;
                curWater += ( curHeight - A[cur] );
            }
            if( cur < n && A[cur] >= curHeight ) sum += curWater;
            else ++cur;
        }
        //from right to left
        cur = n-1;
        while( cur >= 0 && A[cur]==0 ) --cur;
        while( cur >= 0 ){
            int curWater = 0;
            int curHeight = A[cur];
            while( --cur >= 0 ){
                if( A[cur] > curHeight ) break;
                curWater += ( curHeight-A[cur] );
            }
            if( cur >= 0 && A[cur] > curHeight ) sum += curWater;
            else --cur;
        }
        return sum;
    }
};