class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return maxSubArray( A, 0, n-1 );
    }
    int maxSubArray( int A[], int left, int right ){
        if( left==right ) return A[left];
        int mid = (left+right)/2;
        int maxLeft = A[left];
        int maxRight = A[right];
        if( mid >= left )
            maxLeft = maxSubArray( A, left, mid );
        if( mid+1 <= right ){
            maxRight = maxSubArray( A, mid+1, right );
        }
        int maxMidL = A[mid];
        int sum = 0;
        for( int i = mid; i >= left; --i ){
            sum += A[i];
            if( sum > maxMidL ){
                maxMidL = sum;
            }
        }
        int maxMidR = 0;
        if( mid+1 <= right ){
            maxMidR = A[ mid+1 ];
            sum = 0;
            for( int i = mid+1; i <= right; ++i ){
                sum += A[i];
                if( sum > maxMidR ){
                    maxMidR = sum;
                }
            }
        }   
        return max( max( maxLeft, maxRight), maxMidR+maxMidL );
    }
};