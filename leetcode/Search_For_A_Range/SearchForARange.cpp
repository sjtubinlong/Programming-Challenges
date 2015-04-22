class Solution {
public:
    int low_bound(int A[], int n, int target){
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(A[mid] == target){
                high = mid;
                if(low == high) break;
            }else if(A[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        if(high != low) return -1;
        return low;
    }
    
    int high_bound(int A[], int n, int target){
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(A[mid] == target){
                low = mid + 1;
            }else if(A[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        if(low - 1 < 0 || A[low-1] != target) return -1;
        return low - 1;
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ans;
        ans.push_back(low_bound(A, n, target));
        ans.push_back(high_bound(A, n, target));
        return ans;
    }
};
