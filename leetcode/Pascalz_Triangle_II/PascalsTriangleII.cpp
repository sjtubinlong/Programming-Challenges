class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 0);
        for(int i = 0; i <= rowIndex; ++i){
            ans[0] = 1;
            int prev = 1;
            for(int j = 1; j <= i; ++j){
                int cur = ans[j];
                ans[j] = ans[j] + prev;
                prev = cur;
            }
            ans[i] = 1;
        }
        return ans;
    }
};
