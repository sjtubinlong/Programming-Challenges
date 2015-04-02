class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n = num.size();
        if(n <= 2) return num[0];
        
        int ans, count = 0;
        for(int i = 0; i < n; ++i){
            if(count == 0) ans = num[i];
            if(num[i] == ans) ++count;
            else --count;
        }
        return ans;
    }
};
