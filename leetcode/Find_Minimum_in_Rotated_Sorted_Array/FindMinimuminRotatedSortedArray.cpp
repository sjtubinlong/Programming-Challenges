// binary search, and analyse by drawing simple graph
class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        if(n == 1) return num[0];
        
        int low = 0, high = n - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(num[mid] < num[low]){
                high = mid;
            }else if(num[mid] < num[high]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return num[low];
    }
};
