class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(A[mid] == target){
                high = mid;
                if(high == low){
                    break;
                }
            }else if (A[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};
