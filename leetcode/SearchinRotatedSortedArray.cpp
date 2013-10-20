class Solution {
public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int left = 0;
        int right = n-1;
        while( left <= right ){
            int mid = left+(right-left)/2;
            if( A[mid]==target ){
                return mid;
            }
            if( A[mid] >= A[left] ){
                if( target >= A[left] && target < A[mid] ){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{
                if( target <= A[right] && target > A[mid] ){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};