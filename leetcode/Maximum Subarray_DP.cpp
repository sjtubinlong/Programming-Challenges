class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int max = A[0];
        int sum = 0;
        for( int i = 0; i < n; ++i ){
            if( sum > 0 ){
                sum = A[i] + sum;
            }else{
                sum = A[i];
            }
            if( sum > max ) max = sum;
        }
        return max;
    }
};