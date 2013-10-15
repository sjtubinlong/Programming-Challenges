class Solution {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( n==0 || n==1 ) return 1;
        int a = 0, b = 1;
        for( int i = 0; i < n ; ++i ){
            b = a + b;
            a = b - a;
        }
        return b;
    }
};