class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( n==0 ) return 0;
        if( n==1 && A[0]==elem ) return 0;
        int i = 0, j = 0;
        while( j < n ){
            if( A[j] != elem ){
                A[i++] = A[j];
            }
            ++j;
        }
        return i;
    }
};