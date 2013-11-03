class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i = 0;
        while( i < n ){
            if( A[i] <= 0 || A[i] > n ) ++i;
            else if( A[i] == i+1 || A[ A[i]-1 ]== A[i] ) ++i;
            else{
                int temp = A[i];
                A[i] = A[ temp -1 ];
                A[temp-1] = temp;
            }
        }
        for( int i = 0; i < n; ++i ) {
            if( A[i] != i+1 ) return i+1;
        }
        return n+1;
    }
};