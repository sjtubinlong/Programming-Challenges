class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans = ans * 26 + s[i] - 'A' + 1;
        }
        return ans;
    }
};
