int findMin(int num[], int n) {
    int low = 0, high = n - 1;
    while(low < high){
        int mid = (low + high) / 2;
        if(num[mid] > num[high]){
            low = mid + 1;
        }else{
            if(num[mid] < num[high]){
                high = mid;
            }else{
                --high;
            }
        }
    }
    return num[high];
}
