class Solution {
public:
    int rob(vector<int> &num) {
        int n = num.size();
        if(n == 0) return 0;
        if(n == 1) return num[0];
        
        int prev_yes = 0, prev_no = 0;
        for(int i = 0; i < n; ++i){
            int temp = prev_no;
            prev_no = max(prev_yes, prev_no);
            prev_yes = temp + num[i];
        }
        return max(prev_yes, prev_no);
    }
};
