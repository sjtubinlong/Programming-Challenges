class Solution {
public:
    int search(int A[], int n,  int target){
        int low = 0;
        int high = n-1;
        while( low <= high )
        {
            int mid = low + (high - low)/2;
            if( A[mid] == target ) return mid;
            if( A[mid] >= A[low] )
            {
                if( target >= A[low] && target < A[mid] )
                {
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }else{
                if(target > A[mid] && target <= A[high] )
                {
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};