class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( m+n == 0 ) return 0.0;
        int i = 0, j = 0, k = 0;
        vector<int> C( m+n+1, 0 );
        while( i < m && j < n ){
            if( A[i] < B[j] ){
                C[k++] = A[i++];
            }else if( A[i] > B[j] ){
                C[k++] = B[j++];
            }else{
                C[k++] = A[i++];
                C[k++] = B[j++];
            }
        }
        while( i < m ){
            C[k++] = A[i++];
        }
        while( j < n ){
            C[k++] = B[j++];
        }
        if( (m+n)%2 ){
            return C[ (m+n+1)/2-1];
        }
        
        return double( C[(m+n)/2-1] + C[(m+n)/2])/2;
    }
};