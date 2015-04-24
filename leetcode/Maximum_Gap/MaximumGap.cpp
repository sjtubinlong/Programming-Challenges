class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        vector<int> bucket[2];
        for(int i = 0; i < 32; ++i){
            int flag = 1 << i;
            for(int j = 0; j < n; ++j){
                if(nums[j]&flag){
                    bucket[1].push_back(nums[j]);
                }else{
                    bucket[0].push_back(nums[j]);
                }
            }
            int j = 0;
            for(;j < bucket[0].size(); ++j){
                nums[j] = bucket[0][j];
            }
            for(int k = 0; k < bucket[1].size(); ++k, ++j){
                nums[j] = bucket[1][k];
            }
            bucket[0].clear();
            bucket[1].clear();
        }
        int ans = nums[1] - nums[0];
        for(int i = 2; i < n; ++i){
            ans = max(ans, nums[i] - nums[i-1]);
        }
        return ans;
    }
};
