class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int left = 0, right = n-1;
        while( left < right ){
            int mid = left + ( right - left)/2;
            if( A[mid] == target ) return mid;
            if( A[mid] > target ) right = mid-1;
            else left = mid+1;
        }
        if( left==right ){
            if( A[left] >= target )
                return left;
            else return left+1;
        }
        return left;
    }
};