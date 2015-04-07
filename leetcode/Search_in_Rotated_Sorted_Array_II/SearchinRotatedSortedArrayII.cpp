bool search(int A[], int n, int target) {
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(A[mid] == target) return true;
        if(A[mid] > A[high]){
            if(target >= A[low] && target < A[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else if(A[mid] == A[high]){
                high--;
        }else{
            if(target > A[mid] && target <= A[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return false;
}
