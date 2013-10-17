class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int one = 0, two = 0, three = 0;
        for( int i = 0; i < n; ++i ){
            two |= ( one & A[i] );
            one ^= A[i];
            three = one&two;
            one &= ~three;
            two &= ~three;
        }
        return one;
    }
};