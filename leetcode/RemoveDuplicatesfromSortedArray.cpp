class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( n==0 || n==1 ) return n;
        int i = 1,j = 1;
        while( j < n ){
            if( A[j] != A[i-1] ){
                A[i++] = A[j];
            }
            ++j;
        }
        return i;
    }
};