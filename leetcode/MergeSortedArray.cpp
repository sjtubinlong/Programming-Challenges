class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( n==0 ) return;
        int* C = new int[m+n+1];
        int i = 0, j = 0, k = 0;
        while( i < m && j < n ){
            if( A[i] < B[j] ){
                C[k++] = A[i++];
            }else{
                C[k++] = B[j++];
            }
        }
        while( i < m ){
            C[k++] = A[i++];
        }
        while( j < n ){
            C[k++] = B[j++];
        }
        for( i = 0; i != k; ++i ){
            A[i] = C[i];
        }
        delete [] C;
    }
};