int findPeakElement(int num[], int n) {
    if(n == 0) return -1;
    if(n == 1) return 0;
    
    int low = 0, high = n - 1;
    while(low < high){
        int mid = ((low + high)>>1);
        if(num[mid] > num[mid+1]){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    return high;
}
