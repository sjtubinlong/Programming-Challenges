class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if(n == 0) return -1;
        if(n == 1) return 0;
        if(num[0] > num[1]) return 0;
        if(num[n-1] > num[n-2]) return n-1;
        
        for(int i = 1; i < n-1; ++i){
            if(num[i] > num[i-1] && num[i] > num[i+1]){
                return i;
            }    
        }
        return -1;
    }
};
