/*
0 0 0 
0 0 1
------ n = 1 
0 1 1 
0 1 0 
------ n = 2
1 1 0 
1 1 1 
1 0 1 
1 0 0 
------ n = 3
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        if(n == 0) { 
            ans.push_back(0); //? fuck leetcode
            return ans;
        }
        ans.push_back(0);
        ans.push_back(1);
        int i = 2;
        while(i <= n){
            int m = ans.size();
            for(int j = m - 1; j >= 0; --j) {
                int flip = 1 << (i - 1);
                ans.push_back(ans[j]^flip);
            }
            ++i;
        }
        return ans;
    }
};
