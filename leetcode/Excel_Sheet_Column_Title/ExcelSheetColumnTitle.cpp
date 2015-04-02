class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        if(n <= 0) return ans;
        bool v = false;
        while(n){
            ans += 'A' + (n - 1) % 26;
            n = (n - 1) / 26;
        }
        int i = 0, j = ans.size() - 1;
        while(i < j){
            ans[i] = ans[i] + ans[j];
            ans[j] = ans[i] - ans[j];
            ans[i] = ans[i] - ans[j];
            ++i;
            --j;
        }
        return ans;
    }
};
